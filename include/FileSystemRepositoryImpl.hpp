#pragma once

#include "Repository.hpp"

namespace synclib {

class FileSystemRepositoryImpl : public Repository {
public:
    FileSystemRepositoryImpl(const std::string& rootDirectoryPath);
    
    virtual std::shared_ptr<Directory> getDirectoryTree() override;
    
private:
    const std::string rootDirectoryPath;
};

}
