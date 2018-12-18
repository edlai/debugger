# LDD - print shared library dependencies

print shared library dependencies if there is no ldd command running in Embedded Linux System.

在嵌入式系統上，如果沒有 `ldd` 這個命令的話，可以用下面的命令的組合直接讀取 `/proc/pid` 底下的資料來得知所運行的相依性函式庫。

## Usage

使用範例，這是使用範例使用 `awk`等命令的組合來查看 `rsyslogd` 運行時所需要的函示庫。

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

## Appendix

如果嵌入式系統尚有 `ldd` 或 `objdump` 的話，就可以不用這麼麻煩，直接用`ldd` 或 `objdump`即可取得程式運行所需函示庫。

- 透過 `ldd` 的運行結果。

```
# ldd /usr/sbin/rsyslogd
	linux-vdso.so.1 =>  (0x00007ffee1fa7000)
	libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007fec2b1e9000)
	libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007fec2afcc000)
	libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007fec2adc8000)
	librt.so.1 => /lib/x86_64-linux-gnu/librt.so.1 (0x00007fec2abc0000)
	libestr.so.0 => /usr/lib/x86_64-linux-gnu/libestr.so.0 (0x00007fec2a9bc000)
	libjson-c.so.2 => /lib/x86_64-linux-gnu/libjson-c.so.2 (0x00007fec2a7b1000)
	libuuid.so.1 => /lib/x86_64-linux-gnu/libuuid.so.1 (0x00007fec2a5ac000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fec2a1e2000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fec2b403000)
```

- 透過 `objdump` 的運行結果。

```
# objdump -p /usr/sbin/rsyslogd | grep NEEDED
  NEEDED               libz.so.1
  NEEDED               libpthread.so.0
  NEEDED               libdl.so.2
  NEEDED               librt.so.1
  NEEDED               libestr.so.0
  NEEDED               libjson-c.so.2
  NEEDED               libuuid.so.1
  NEEDED               libc.so.6
```

## Reference

- [How to find out the dynamic libraries executables loads when run?](https://unix.stackexchange.com/questions/120015/how-to-find-out-the-dynamic-libraries-executables-loads-when-run)
