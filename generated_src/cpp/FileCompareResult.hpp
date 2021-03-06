// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from directory_tree.djinni

#pragma once

#include <functional>

namespace synclib {

enum class FileCompareResult : int {
    /** The compared files are unrelated */
    Unrelated,
    /** The compared files have the same path and content */
    Equal,
    /** The compared files have the same path but different contents */
    Conflicting,
};

}  // namespace synclib

namespace std {

template <>
struct hash<::synclib::FileCompareResult> {
    size_t operator()(::synclib::FileCompareResult type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
