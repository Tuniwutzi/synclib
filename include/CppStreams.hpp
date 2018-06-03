#include "InputStream.hpp"
#include "OutputStream.hpp"

#include <istream>
#include <ostream>

namespace synclib {

class CppInputStream : public InputStream {
public:
    virtual std::istream& getRawStream() = 0;
};
class CppOutputStream : public OutputStream {
public:
    virtual std::ostream& getRawStream() = 0;
};

}
