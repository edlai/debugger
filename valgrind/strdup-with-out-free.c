#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int main(void){

  char a[] = "strdup";
  char *b;

  b = strdup(a);
  printf("b[]=\"%s\"\n", b);
  //free(b);
  return 0;
}


/**
 to test memory-leak without calling free function after performing strdup
 - normally, user should call free before exit
 - there is the result of valgrind which warning use should check memory-leak

# valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all  -v ./strdup-with-out-free

==9326== Memcheck, a memory error detector
==9326== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9326== Using Valgrind-3.14.0-353a3587bb-20181007X and LibVEX; rerun with -h for copyright info
==9326== Command: ./strdup-with-out-free
==9326==
--9326-- Valgrind options:
--9326--    --tool=memcheck
--9326--    --leak-check=full
--9326--    --show-leak-kinds=all
--9326--    -v
--9326-- Contents of /proc/version:
--9326--   Linux version 4.4.0-127-generic (buildd@lcy01-amd64-023) (gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) ) #153-Ubuntu SMP Sat May 19 10:58:46 UTC 2018
--9326--
--9326-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-lzcnt-rdtscp-sse3-avx-avx2-bmi
--9326-- Page sizes: currently 4096, max supported 4096
--9326-- Valgrind library directory: /usr/local/lib/valgrind
--9326-- Reading syms from /root/test/strdup-with-out-free
--9326-- Reading syms from /lib/x86_64-linux-gnu/ld-2.23.so
--9326--   Considering /lib/x86_64-linux-gnu/ld-2.23.so ..
--9326--   .. CRC mismatch (computed aa979a42 wanted 9019bbb7)
--9326--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.23.so ..
--9326--   .. CRC is valid
--9326-- Reading syms from /usr/local/lib/valgrind/memcheck-amd64-linux
--9326--    object doesn't have a dynamic symbol table
--9326-- Scheduler: using generic scheduler lock implementation.
--9326-- Reading suppressions file: /usr/local/lib/valgrind/default.supp
==9326== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-9326-by-root-on-???
==9326== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-9326-by-root-on-???
==9326== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-9326-by-root-on-???
==9326==
==9326== TO CONTROL THIS PROCESS USING vgdb (which you probably
==9326== don't want to do, unless you know exactly what you're doing,
==9326== or are doing some strange experiment):
==9326==   /usr/local/lib/valgrind/../../bin/vgdb --pid=9326 ...command...
==9326==
==9326== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==9326==   /path/to/gdb ./strdup-with-out-free
==9326== and then give GDB the following command
==9326==   target remote | /usr/local/lib/valgrind/../../bin/vgdb --pid=9326
==9326== --pid is optional if only one valgrind process is running
==9326==
--9326-- REDIR: 0x401cfd0 (ld-linux-x86-64.so.2:strlen) redirected to 0x5811397d (vgPlain_amd64_linux_REDIR_FOR_strlen)
--9326-- REDIR: 0x401b920 (ld-linux-x86-64.so.2:index) redirected to 0x58113997 (vgPlain_amd64_linux_REDIR_FOR_index)
--9326-- Reading syms from /usr/local/lib/valgrind/vgpreload_core-amd64-linux.so
--9326-- Reading syms from /usr/local/lib/valgrind/vgpreload_memcheck-amd64-linux.so
==9326== WARNING: new redirection conflicts with existing -- ignoring it
--9326--     old: 0x0401cfd0 (strlen              ) R-> (0000.0) 0x5811397d vgPlain_amd64_linux_REDIR_FOR_strlen
--9326--     new: 0x0401cfd0 (strlen              ) R-> (2007.0) 0x04c310c0 strlen
--9326-- REDIR: 0x401bb40 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4c32170 (strcmp)
--9326-- REDIR: 0x401dd30 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x4c35ab0 (mempcpy)
--9326-- Reading syms from /lib/x86_64-linux-gnu/libc-2.23.so
--9326--   Considering /lib/x86_64-linux-gnu/libc-2.23.so ..
--9326--   .. CRC mismatch (computed 7a8ee3e4 wanted a5190ac4)
--9326--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.23.so ..
--9326--   .. CRC is valid
--9326-- REDIR: 0x4ecaa00 (libc.so.6:strcasecmp) redirected to 0x4a28770 (_vgnU_ifunc_wrapper)
--9326-- REDIR: 0x4ec6280 (libc.so.6:strcspn) redirected to 0x4a28770 (_vgnU_ifunc_wrapper)
--9326-- REDIR: 0x4ecccf0 (libc.so.6:strncasecmp) redirected to 0x4a28770 (_vgnU_ifunc_wrapper)
--9326-- REDIR: 0x4ec86f0 (libc.so.6:strpbrk) redirected to 0x4a28770 (_vgnU_ifunc_wrapper)
--9326-- REDIR: 0x4ec8a80 (libc.so.6:strspn) redirected to 0x4a28770 (_vgnU_ifunc_wrapper)
--9326-- REDIR: 0x4eca14b (libc.so.6:memcpy@GLIBC_2.2.5) redirected to 0x4a28770 (_vgnU_ifunc_wrapper)
--9326-- REDIR: 0x4ec8400 (libc.so.6:rindex) redirected to 0x4c30a40 (rindex)
--9326-- REDIR: 0x4ec6720 (libc.so.6:strlen) redirected to 0x4c31000 (strlen)
--9326-- REDIR: 0x4ebf130 (libc.so.6:malloc) redirected to 0x4c2ddcf (malloc)
--9326-- REDIR: 0x4ecf470 (libc.so.6:__GI_memcpy) redirected to 0x4c32da0 (__GI_memcpy)
--9326-- REDIR: 0x4ed1760 (libc.so.6:strchrnul) redirected to 0x4c355e0 (strchrnul)
--9326-- REDIR: 0x4eca3b0 (libc.so.6:__GI_mempcpy) redirected to 0x4c357e0 (__GI_mempcpy)
b[]="strdup"
--9326-- REDIR: 0x4ebf4f0 (libc.so.6:free) redirected to 0x4c2eec9 (free)
==9326==
==9326== HEAP SUMMARY:
==9326==     in use at exit: 7 bytes in 1 blocks
==9326==   total heap usage: 2 allocs, 1 frees, 1,031 bytes allocated
==9326==
==9326== Searching for pointers to 1 not-freed blocks
==9326== Checked 60,368 bytes
==9326==
==9326== 7 bytes in 1 blocks are definitely lost in loss record 1 of 1
==9326==    at 0x4C2DE56: malloc (vg_replace_malloc.c:299)
==9326==    by 0x4EC6489: strdup (strdup.c:42)
==9326==    by 0x400609: main (in /root/test/strdup-with-out-free)
==9326==
==9326== LEAK SUMMARY:
==9326==    definitely lost: 7 bytes in 1 blocks
==9326==    indirectly lost: 0 bytes in 0 blocks
==9326==      possibly lost: 0 bytes in 0 blocks
==9326==    still reachable: 0 bytes in 0 blocks
==9326==         suppressed: 0 bytes in 0 blocks
==9326==
==9326== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
==9326== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

*/
