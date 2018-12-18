# gdb/ddd

## Requirements

- gdb `apt install gdb`

## Usage

- using `--args` for commandline args, [How do I run a program with commandline args using gdb within a bash script?](https://stackoverflow.com/questions/6121094/how-do-i-run-a-program-with-commandline-args-using-gdb-within-a-bash-script)
- trace code with using `break 1`, `run`, `n` and so on

``` sh

# gcc -ggdb3 -o strdup-with-out-free strdup-with-out-free.c

# gdb ./strdup-with-out-free
GNU gdb (Ubuntu 7.11.1-0ubuntu1~16.5) 7.11.1
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./strdup-with-out-free...done.
(gdb) break 1
Breakpoint 1 at 0x4005de: file strdup-with-out-free.c, line 1.
(gdb) run
Starting program: /root/test/strdup-with-out-free

Breakpoint 1, main () at strdup-with-out-free.c:6
6       int main(void){
(gdb) n
8         char a[] = "strdup";
(gdb) n
11        b = strdup(a);
(gdb) n
12        printf("b[]=\"%s\"\n", b);
(gdb) n
b[]="strdup"
15        return 0;
(gdb) n
16      }
(gdb) n
__libc_start_main (main=0x4005d6 <main>, argc=1, argv=0x7fffffffe5d8, init=<optimized out>,
    fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffe5c8) at ../csu/libc-start.c:325
325     ../csu/libc-start.c: No such file or directory.
(gdb)

```
