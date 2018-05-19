#include "FileSystemRepositoryImpl.hpp"

#include "BasicException.hpp"
#include "DirectoryImpl.hpp"
#include "File.hpp"

#include "FileSystem/Directory.hpp"
#include "FileSystem/File.hpp"
#include "FileSystem/Path.hpp"

namespace synclib {

std::shared_ptr<Repository> Repository::createFromFileSystem(const std::string& directoryPath) {
    return std::make_shared<FileSystemRepositoryImpl>(directoryPath);
}

FileSystemRepositoryImpl::FileSystemRepositoryImpl(const std::string& path)
    :rootDirectoryPath(path) {
}

static void fillDirectory(const std::shared_ptr<DirectoryImpl>& dir) {
    cppsupport::FileSystem::Directory fsDir(dir->getPath());
    
    auto files = fsDir.enumerateFiles("*", false);
    for (const auto& file : files) {
        auto path = file.getPath();
        auto name = cppsupport::FileSystem::Path::GetFileName(path, true);
        dir->addFile(File(name, "hash"));
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
