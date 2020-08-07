// FIXME

#include <stdio.h>
int main() {
  char s[101];
  while(scanf("%s", s) != EOF) {
    getchar();
    printf("%s\n", s);
  }
  return 0;
}