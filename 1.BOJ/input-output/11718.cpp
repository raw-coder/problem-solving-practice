#include <stdio.h>
int main() {
  char s[101];
  while(scanf("%[^\n]", s) != -1) {
    getchar();
    printf("%s\n", s);
  }
  return 0;
}