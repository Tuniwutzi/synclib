// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from directory_tree.djinni

#pragma once

#include <memory>
#include <string>

namespace synclib {

class Directory;

class DirectoryTree {
public:
    virtual ~DirectoryTree() {}

    static std::shared_ptr<Directory> buildFromJson(const std::string & json);
};

}  // namespace synclib