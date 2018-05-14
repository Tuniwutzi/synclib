#include "DirectoryTree.hpp"

#include "BasicException.hpp"
#include "directorytree/DirectoryImpl.hpp"

#include "json11.hpp"

namespace synclib {

std::shared_ptr<Directory> DirectoryTree::buildFromJson(const std::string& json) {
    std::string error;
    auto data = json11::Json::parse(json, error);
    if (error.empty()) {
        return std::make_shared<DirectoryImpl>("name", false);
    } else {
        using namespace std::string_literals;
        throw BasicException("Error parsing json: "s + error);
    }
}

}
