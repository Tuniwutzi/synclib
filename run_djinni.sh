out_dir="./generated_src"
rm $out_dir

java_out="$out_dir/java"
jni_out="$out_dir/jni"
cpp_out="$out_dir/cpp"

java_package="de.jb.synclib"
namespace="synclib"

djinni_file="idl/sync_lib.djinni"

dependencies/djinni/src/run \
   --java-out $java_out \
   --java-package $java_package \
   --ident-java-field mFooBar \
   --ident-java-enum FOO_BAR \
   --java-nonnull-annotation android.support.annotation.NonNull \
   --java-nullable-annotation android.support.annotation.Nullable \
   \
   --cpp-out $cpp_out \
   --cpp-namespace $namespace \
   --cpp-optional-template "std::experimental::optional" \
   --cpp-optional-header "<experimental/optional>" \
   --ident-cpp-enum FooBar \
   --ident-cpp-type FooBar \
   --ident-cpp-field fooBar \
   --ident-cpp-method fooBar \
   --ident-cpp-local fooBar \
   --ident-cpp-enum-type FooBar \
   --ident-cpp-type-param fooBar \
   --ident-cpp-file FooBar \
   \
   --jni-out $jni_out \
   --ident-jni-class NativeFooBar \
   --ident-jni-file NativeFooBar \
   \
   --idl $djinni_file
