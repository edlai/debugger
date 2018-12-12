#include <stdio.h>
#include <string.h>

int main(void){
  char a[] = "strdup";
  char *b;

  b = strdup(a);
  printf("b[]=\"%s\"\n", b);
  return 0;
}
