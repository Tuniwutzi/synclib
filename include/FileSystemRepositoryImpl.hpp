#pragma once

#include "Repository.hpp"
#include "DirectoryImpl.hpp"

namespace synclib {

class FileSystemRepositoryImpl : public Repository {
public:
    FileSystemRepositoryImpl(const std::string& rootDirectoryPath);
    
    virtual std::shared_ptr<Directory> getDirectoryTree() override;
    
    virtual std::shared_ptr<InputStream> read(const File& from) const override;
    virtual std::shared_ptr<OutputStream> write(const File& to) override;
    
private:
    void fillDirectory(const std::shared_ptr<DirectoryImpl>& dir);
    
    const std::string rootDirectoryPath;
};

}
