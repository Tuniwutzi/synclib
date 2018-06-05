// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from stream.djinni

#pragma once

#include "OutputStream.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeOutputStream final : ::djinni::JniInterface<::synclib::OutputStream, NativeOutputStream> {
public:
    using CppType = std::shared_ptr<::synclib::OutputStream>;
    using CppOptType = std::shared_ptr<::synclib::OutputStream>;
    using JniType = jobject;

    using Boxed = NativeOutputStream;

    ~NativeOutputStream();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeOutputStream>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeOutputStream>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeOutputStream();
    friend ::djinni::JniClass<NativeOutputStream>;
    friend ::djinni::JniInterface<::synclib::OutputStream, NativeOutputStream>;

};

}  // namespace djinni_generated