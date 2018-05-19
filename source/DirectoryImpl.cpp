#include "DirectoryImpl.hpp"

#include "BasicException.hpp"

#include "File.hpp"

#include "FileSystem/Path.hpp"

namespace synclib {

DirectoryImpl::DirectoryImpl(const std::string& path, bool root)
    :path(path)
    ,root(root) {
}

const std::string& DirectoryImpl::getPath() const {
    return this->path;
}
void DirectoryImpl::addFile(const File& file) {
    this->files.push_back(file);
}
void DirectoryImpl::addSubDirectory(const std::shared_ptr<Directory>& directory) {
    this->subDirectories.push_back(directory);
}

std::string DirectoryImpl::getName() const {
    return cppsupport::FileSystem::Path::GetFileName(this->path, true);
}
bool DirectoryImpl::isRoot() const {
    return this->root;
}

std::vector<std::shared_ptr<Directory>> DirectoryImpl::getSubdirectories() const {
    return this->subDirectories;
}

std::vector<File> DirectoryImpl::getFiles(bool recursive) const {
    return this->files;
}

}
