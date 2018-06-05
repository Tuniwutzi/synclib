// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from directory_tree.djinni

package de.jb.synclib;

import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Directory {
    @NonNull
    public abstract String getName();

    public abstract boolean isRoot();

    @NonNull
    public abstract ArrayList<Directory> getSubdirectories();

    @NonNull
    public abstract ArrayList<File> getFiles(boolean recursive);

    /**
     * Compares the files within two directories
     * @return a list differences between the directories
     */
    @NonNull
    public static native CompareResult compareDirectories(@Nullable Directory a, @Nullable Directory b);

    /** Compares the passed files */
    @NonNull
    public static native FileCompareResult compareFiles(@NonNull File a, @NonNull File b);

    private static final class CppProxy extends Directory
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        @Override
        public String getName()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getName(this.nativeRef);
        }
        private native String native_getName(long _nativeRef);

        @Override
        public boolean isRoot()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_isRoot(this.nativeRef);
        }
        private native boolean native_isRoot(long _nativeRef);

        @Override
        public ArrayList<Directory> getSubdirectories()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getSubdirectories(this.nativeRef);
        }
        private native ArrayList<Directory> native_getSubdirectories(long _nativeRef);

        @Override
        public ArrayList<File> getFiles(boolean recursive)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getFiles(this.nativeRef, recursive);
        }
        private native ArrayList<File> native_getFiles(long _nativeRef, boolean recursive);
    }
}
