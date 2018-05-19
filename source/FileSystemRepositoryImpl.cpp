#include "FileSystemRepositoryImpl.hpp"

#include "BasicException.hpp"
#include "DirectoryImpl.hpp"

namespace synclib {

std::shared_ptr<Repository> Repository::createFromFileSystem(const std::string& directoryPath) {
    return std::make_shared<FileSystemRepositoryImpl>(directoryPath);
}

FileSystemRepositoryImpl::FileSystemRepositoryImpl(const std::string& path)
    :rootDirectoryPath(path) {
}

std::shared_ptr<Directory> FileSystemRepositoryImpl::getDirectoryTree() {
    return std::make_shared<DirectoryImpl>(this->rootDirectoryPath, true);
}

}
