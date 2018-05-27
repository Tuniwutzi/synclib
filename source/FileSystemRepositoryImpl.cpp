#include "FileSystemRepositoryImpl.hpp"

#include "BasicException.hpp"
#include "DirectoryImpl.hpp"
#include "File.hpp"

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

static std::string makeHash(cppsupport::FileSystem::File& file) {
    auto fstream = file.openRead(true);
    auto buffer = std::vector<char>(std::istreambuf_iterator<char>(fstream), std::istreambuf_iterator<char>());
    
    auto& generator = cppsupport::HashGenerator::SHA1();
    return generator.generateChecksum(buffer, cppsupport::HashGenerator::ChecksumFormats::Hex);
}
static void fillDirectory(const std::shared_ptr<DirectoryImpl>& dir) {
    cppsupport::FileSystem::Directory fsDir(dir->getPath());
    
    auto files = fsDir.enumerateFiles("*", false);
    for (auto& file : files) {
        auto path = file.getPath();
        auto name = cppsupport::FileSystem::Path::GetFileName(path, true);
        dir->addFile(File(name, makeHash(file)));
    }
    
    auto dirs = fsDir.enumerateDirectories("*", false);
    for (const auto& fsSubDir : dirs) {
        auto subDir = std::make_shared<DirectoryImpl>(fsSubDir.getPath(), false);
        fillDirectory(subDir);
        dir->addSubDirectory(subDir);
    }
}
std::shared_ptr<Directory> FileSystemRepositoryImpl::getDirectoryTree() {
    auto rv = std::make_shared<DirectoryImpl>(this->rootDirectoryPath, true);
    fillDirectory(rv);
    
    return rv;
}

}
