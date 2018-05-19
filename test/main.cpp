#include <iostream>

#include "Repository.hpp"
#include "Directory.hpp"

using namespace synclib;

int main(int argc, char** argv) {
    auto repo = Repository::createFromFileSystem("asd");
    auto dir = repo->getDirectoryTree();
    std::cout << dir->getName() << std::endl;
    return 0;
}
