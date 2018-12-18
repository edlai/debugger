# LDD

print shared library dependencies if there is no ldd command running in Embedded Linux System.


## Usage

- Usage
```
$ awk '/\.so/{print $6}' /proc/`pidof rsyslogd`/maps | sort -u
```

- Result
```
/lib/x86_64-linux-gnu/ld-2.23.so
/lib/x86_64-linux-gnu/libc-2.23.so
/lib/x86_64-linux-gnu/libdl-2.23.so
/lib/x86_64-linux-gnu/libjson-c.so.2.0.0
/lib/x86_64-linux-gnu/libnsl-2.23.so
/lib/x86_64-linux-gnu/libnss_compat-2.23.so
/lib/x86_64-linux-gnu/libnss_files-2.23.so
/lib/x86_64-linux-gnu/libnss_nis-2.23.so
/lib/x86_64-linux-gnu/libpthread-2.23.so
/lib/x86_64-linux-gnu/librt-2.23.so
/lib/x86_64-linux-gnu/libuuid.so.1.3.0
/lib/x86_64-linux-gnu/libz.so.1.2.8
/usr/lib/rsyslog/imklog.so
/usr/lib/rsyslog/imuxsock.so
/usr/lib/rsyslog/lmnet.so
/usr/lib/x86_64-linux-gnu/libestr.so.0.0.0
```

## Reference

- [How to find out the dynamic libraries executables loads when run?](https://unix.stackexchange.com/questions/120015/how-to-find-out-the-dynamic-libraries-executables-loads-when-run)
