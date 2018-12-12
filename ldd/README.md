# LDD

print shared library dependencies if there is no ldd command running in embedded system.


## Usage

- usage
```
awk '/\.so/{print $6}' /proc/`pidof da_adaptor`/maps | sort -u
```

## Reference

- [How to find out the dynamic libraries executables loads when run?](https://unix.stackexchange.com/questions/120015/how-to-find-out-the-dynamic-libraries-executables-loads-when-run)
