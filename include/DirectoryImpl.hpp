#pragma once

#include "Directory.hpp"

namespace synclib {

class DirectoryImpl : public Directory {
public:
    DirectoryImpl(const std::string& name, bool root);
    
    virtual std::string getName() const override;

    virtual bool isRoot() const override;

    virtual std::vector<std::shared_ptr<Directory>> getSubdirectories() const override;

    virtual std::vector<File> getFiles(bool recursive) const override;
};

}
