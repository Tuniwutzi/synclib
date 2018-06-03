#include "CppStreams.hpp"

#include <fstream>

namespace synclib {

class FileSystemInputStream : public CppInputStream {
public:
    FileSystemInputStream(std::ifstream&& stream);
    
    std::istream& getRawStream() override;
    
private:
    std::ifstream stream;
};

class FileSystemOutputStream : public CppOutputStream {
public:
    FileSystemOutputStream(std::ofstream&& stream);
    
    // From CppOutputStream:
    std::ostream& getRawStream() override;
    
    // From OutputStream:
    void copy(const std::shared_ptr<InputStream>& from) override;
    
private:
    std::ofstream stream;
};

}
