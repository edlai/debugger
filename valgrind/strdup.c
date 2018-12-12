#include <stdio.h>
#include <string.h>

int main(void){
  char a[] = "strdup";
  char *b;

  b = strdup(a);
  printf("b[]=\"%s\"\n", b);
  return 0;
}

/* an example of memory leak for usage of strdup

root@ed:~/test# valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all  ./test
==9218== Memcheck, a memory error detector
==9218== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9218== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==9218== Command: ./test
==9218==
b[]="strdup"
==9218==
==9218== HEAP SUMMARY:
==9218==     in use at exit: 7 bytes in 1 blocks
==9218==   total heap usage: 2 allocs, 1 frees, 1,031 bytes allocated
==9218==
==9218== 7 bytes in 1 blocks are definitely lost in loss record 1 of 1
==9218==    at 0x4C2DE56: malloc (vg_replace_malloc.c:299)
==9218==    by 0x4EC6489: strdup (strdup.c:42)
==9218==    by 0x400609: main (in /root/test/test)
==9218==
==9218== LEAK SUMMARY:
==9218==    definitely lost: 7 bytes in 1 blocks
==9218==    indirectly lost: 0 bytes in 0 blocks
==9218==      possibly lost: 0 bytes in 0 blocks
==9218==    still reachable: 0 bytes in 0 blocks
==9218==         suppressed: 0 bytes in 0 blocks
==9218==
==9218== For counts of detected and suppressed errors, rerun with: -v
==9218== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

*/
