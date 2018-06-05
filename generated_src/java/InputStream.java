// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from stream.djinni

package de.jb.synclib;

import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class InputStream {

    private static final class CppProxy extends InputStream
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
    }
}
