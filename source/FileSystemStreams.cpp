#include "FileSystemStreams.hpp"

namespace synclib {

FileSystemInputStream::FileSystemInputStream(std::ifstream&& stream)
    :stream(std::move(stream)) {
}

std::istream& FileSystemInputStream::getRawStream() {
    return this->stream;
}


FileSystemOutputStream::FileSystemOutputStream(std::ofstream&& stream)
    :stream(std::move(stream)) {
}
std::ostream& FileSystemOutputStream::getRawStream() {
    return this->stream;
}
void FileSystemOutputStream::copy(const std::shared_ptr<InputStream>& from) {
    if (auto cppStream = std::dynamic_pointer_cast<CppInputStream>(from)) {
        auto& rawInputStream = cppStream->getRawStream();
        this->stream << rawInputStream.rdbuf();
        this->stream.flush();
    } else {
        throw std::runtime_error("Copying from non-cpp streams not supported");
    }
}

}
