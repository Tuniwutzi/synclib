#include "DirectoryTree.hpp"

#include "BasicException.hpp"
#include "directorytree/DirectoryImpl.hpp"

#include "File.hpp"

#include "json11.hpp"

namespace synclib {

DirectoryImpl::DirectoryImpl(const std::string& name, bool root) {
}

std::string DirectoryImpl::getName() const {
    return "asd";
}
bool DirectoryImpl::isRoot() const {
    return false;
}

std::vector<std::shared_ptr<Directory>> DirectoryImpl::getSubdirectories() const {
    return {};
}

std::vector<File> DirectoryImpl::getFiles(bool recursive) const {
    return {};
}

}
