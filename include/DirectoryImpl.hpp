#pragma once

#include "Directory.hpp"

namespace synclib {

class DirectoryImpl : public Directory {
public:
    DirectoryImpl(const std::string& path, bool root);
    
    const std::string& getPath() const;
    void addFile(const File& file);
    void addSubDirectory(const std::shared_ptr<Directory>& dir);
    
    
    virtual std::string getName() const override;

    virtual bool isRoot() const override;

    virtual std::vector<std::shared_ptr<Directory>> getSubdirectories() const override;

    virtual std::vector<File> getFiles(bool recursive) const override;
    
private:
    std::string path;
    bool root;
    std::vector<std::shared_ptr<Directory>> subDirectories;
    std::vector<File> files;
};

}
