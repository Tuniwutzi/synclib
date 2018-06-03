#include "DirectoryImpl.hpp"

#include "BasicException.hpp"
#include "File.hpp"
#include "CompareResult.hpp"
#include "FileCompareResult.hpp"

#include "FileSystem/Path.hpp"

namespace synclib {

static std::string toLower(const std::string& str) {
    std::string rv(str); 
    std::transform(rv.begin(), rv.end(), rv.begin(), ::tolower);
    return rv;
}
FileCompareResult Directory::compareFiles(const File& a, const File& b) {
    if (toLower(a.path) == toLower(b.path)) {
        return a.hash == b.hash ? FileCompareResult::Equal : FileCompareResult::Conflicting;
    }
    
    return FileCompareResult::Unrelated;
}
CompareResult Directory::compareDirectories(const std::shared_ptr<Directory>& a, const std::shared_ptr<Directory>& b) {
    std::vector<File> onlyA;
    std::vector<File> onlyB;
    std::vector<File> conflicting;
    
    auto aFiles(a->getFiles(true));
    onlyB = b->getFiles(true);
    
    for (const auto& aFile : aFiles) {
        bool found = false;
        
        for (auto bIt = onlyB.begin(); bIt != onlyB.end();) {
            const auto& bFile = *bIt;
            
            switch (Directory::compareFiles(aFile, bFile)) {
            case FileCompareResult::Conflicting:
                conflicting.push_back(File(aFile.name, aFile.path, std::string()));
            case FileCompareResult::Equal:
                found = true;
                bIt = onlyB.erase(bIt);
                break;
            case FileCompareResult::Unrelated:
                bIt++;
                break;
            }
            
            if (found) {
                break;
            }
        }
        
        if (!found) {
            onlyA.push_back(aFile);
        }
    }
    
    return CompareResult(onlyA, onlyB, conflicting);
}

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

static void fillFlatFileList(const Directory& dir, std::vector<File>& buffer) {
    for (const auto& file : dir.getFiles(false)) {
        buffer.push_back(file);
    }
    for (const auto& subDir : dir.getSubdirectories()) {
        fillFlatFileList(*subDir, buffer);
    }
}
std::vector<File> DirectoryImpl::getFiles(bool recursive) const {
    if (!recursive) {
        return this->files;
    } else {
        std::vector<File> list;
        fillFlatFileList(*this, list);
        return list;
    }
}

}
