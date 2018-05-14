#include <iostream>

#include "DirectoryTree.hpp"
#include "Directory.hpp"

using namespace synclib;

int main(int argc, char** argv) {
    auto dir = DirectoryTree::buildFromJson("null");
    std::cout << dir->getName() << std::endl;
    return 0;
}
