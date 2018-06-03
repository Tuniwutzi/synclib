#include "FileSystemRepositoryImpl.hpp"

#include "BasicException.hpp"
#include "DirectoryImpl.hpp"
#include "File.hpp"
#include "FileSystemStreams.hpp"

#include "FileSystem/Directory.hpp"
#include "FileSystem/File.hpp"
#include "FileSystem/Path.hpp"
#include "HashGenerator.h"

#include <fstream>
#include <sstream>

namespace synclib {

std::shared_ptr<Repository> Repository::createFromFileSystem(const std::string& directoryPath) {
    return std::make_shared<FileSystemRepositoryImpl>(directoryPath);
}

FileSystemRepositoryImpl::FileSystemRepositoryImpl(const std::string& path)
    :rootDirectoryPath(path) {
}

std::shared_ptr<Directory> FileSystemRepositoryImpl::getDirectoryTree() {
    auto rv = std::make_shared<DirectoryImpl>(this->rootDirectoryPath, true);
    fillDirectory(rv);
    
    return rv;
}

std::shared_ptr<InputStream> FileSystemRepositoryImpl::read(const File& from) const {
    std::ifstream stream(cppsupport::FileSystem::Path::Combine(this->rootDirectoryPath, from.path),
                         std::ios_base::in | std::ios_base::binary);
    return std::make_shared<FileSystemInputStream>(std::move(stream));
}
std::shared_ptr<OutputStream> FileSystemRepositoryImpl::write(const File& to) {
    std::ofstream stream(cppsupport::FileSystem::Path::Combine(this->rootDirectoryPath, to.path),
                         std::ios_base::out | std::ios_base::binary);
    return std::make_shared<FileSystemOutputStream>(std::move(stream));
}
void FileSystemRepositoryImpl::remove(const File& file) {
    cppsupport::FileSystem::File cppFile(cppsupport::FileSystem::Path::Combine(this->rootDirectoryPath, file.path));
    cppFile.erase();
}

static std::string makeHash(cppsupport::FileSystem::File& file) {
    auto fstream = file.openRead(true);
    auto buffer = std::vector<char>(std::istreambuf_iterator<char>(fstream), std::istreambuf_iterator<char>());
    
    auto& generator = cppsupport::HashGenerator::SHA1();
    return generator.generateChecksum(buffer, cppsupport::HashGenerator::ChecksumFormats::Hex);
}
void FileSystemRepositoryImpl::fillDirectory(const std::shared_ptr<DirectoryImpl>& dir) {
    cppsupport::FileSystem::Directory fsDir(dir->getPath());
    
    auto files = fsDir.enumerateFiles("*", false);
    for (auto& file : files) {
        auto path = file.getPath();
        auto name = cppsupport::FileSystem::Path::GetFileName(path, true);
        if (name.find(".") == 0) {
            continue;
        }
        auto relativePath = cppsupport::FileSystem::Path::ToRelative(path, this->rootDirectoryPath);
        dir->addFile(File(name, relativePath, makeHash(file)));
    }
    
    auto dirs = fsDir.enumerateDirectories("*", false);
    for (const auto& fsSubDir : dirs) {
        if (cppsupport::FileSystem::Path::GetLastSegment(fsSubDir.getPath()).find(".") == 0) {
            continue;
        }
        auto subDir = std::make_shared<DirectoryImpl>(fsSubDir.getPath(), false);
        fillDirectory(subDir);
        dir->addSubDirectory(subDir);
    }
}

}
