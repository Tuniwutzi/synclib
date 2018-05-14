#pragma once

#include <memory>

namespace synclib {

class BasicException : public std::runtime_error {
public:
    BasicException(const std::string& message)
        :runtime_error(message) {
    }
};

}
