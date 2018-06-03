#include <iostream>

#include "Repository.hpp"
#include "File.hpp"
#include "Directory.hpp"
#include "CompareResult.hpp"

using namespace synclib;

void printLine(const std::string& line, int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "\t";
    }
    std::cout << line << std::endl;
}
void printFile(const File& file, int depth = 0) {
    printLine(file.name + " (" + file.path + ", " + file.hash + ")", depth);
}
static void printFileList(const std::vector<File>& files, int depth = 0) {
    for (const auto& f : files) {
        printFile(f, depth);
    }
}
void printDir(const std::shared_ptr<Directory>& dir, int depth = 0) {
    printLine(dir->getName() + (dir->isRoot() ? " (root)" : ""), depth);
    for (const auto& file : dir->getFiles(false)) {
        printFile(file, depth + 1);
    }
    for (const auto& subDir : dir->getSubdirectories()) {
        printDir(subDir, depth + 1);
    }
}

void printComparison(const CompareResult& result) {
    using namespace std;
    cout << "Only in A:" << endl;
    printFileList(result.onlyInA, 1);
    
    cout << "Only in B:" << endl;
    printFileList(result.onlyInB, 1);
    
    cout << "Conflicts:" << endl;
    printFileList(result.conflicting, 1);
}

int main(int argc, char** argv) {
    auto repoA = Repository::createFromFileSystem(std::string(TESTDIRECTORY) + "/repoA");
    auto repoB = Repository::createFromFileSystem(std::string(TESTDIRECTORY) + "/repoB");
    auto dirA = repoA->getDirectoryTree();
    auto dirB = repoB->getDirectoryTree();
    
    auto comparison = Directory::compareDirectories(dirA, dirB);
    printComparison(comparison);
    
    printDir(dirA);
    return 0;
}
