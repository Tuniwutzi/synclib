// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from directory_tree.djinni

#include "NativeDirectory.hpp"  // my header
#include "Marshal.hpp"
#include "NativeCompareResult.hpp"
#include "NativeFile.hpp"

namespace djinni_generated {

NativeDirectory::NativeDirectory() : ::djinni::JniInterface<::synclib::Directory, NativeDirectory>("de/jb/synclib/Directory$CppProxy") {}

NativeDirectory::~NativeDirectory() = default;


CJNIEXPORT void JNICALL Java_de_jb_synclib_Directory_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::synclib::Directory>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_de_jb_synclib_Directory_00024CppProxy_native_1getName(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::synclib::Directory>(nativeRef);
        auto r = ref->getName();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_de_jb_synclib_Directory_00024CppProxy_native_1isRoot(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::synclib::Directory>(nativeRef);
        auto r = ref->isRoot();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_de_jb_synclib_Directory_00024CppProxy_native_1getSubdirectories(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::synclib::Directory>(nativeRef);
        auto r = ref->getSubdirectories();
        return ::djinni::release(::djinni::List<::djinni_generated::NativeDirectory>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_de_jb_synclib_Directory_00024CppProxy_native_1getFiles(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jboolean j_recursive)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::synclib::Directory>(nativeRef);
        auto r = ref->getFiles(::djinni::Bool::toCpp(jniEnv, j_recursive));
        return ::djinni::release(::djinni::List<::djinni_generated::NativeFile>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_de_jb_synclib_Directory_compareFiles(JNIEnv* jniEnv, jobject /*this*/, jobject j_a, jobject j_b)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::synclib::Directory::compareFiles(::djinni_generated::NativeDirectory::toCpp(jniEnv, j_a),
                                                    ::djinni_generated::NativeDirectory::toCpp(jniEnv, j_b));
        return ::djinni::release(::djinni_generated::NativeCompareResult::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
