#include <iostream>

#include "Repository.hpp"
#include "File.hpp"
#include "Directory.hpp"

using namespace synclib;

void printLine(const std::string& line, int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "  ";
    }
    std::cout << line << std::endl;
}
void printFile(const File& file, int depth = 0) {
    printLine(file.name + " (" + file.hash + ")", depth);
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

int main(int argc, char** argv) {
    auto repo = Repository::createFromFileSystem("/Users/jbuenker/dev/privat/cppsupport");
    auto dir = repo->getDirectoryTree();
    printDir(dir);
    return 0;
}
