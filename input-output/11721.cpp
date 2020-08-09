#include <stdio.h>
int main() {
  char c;
  int i = 0;
  while(scanf("%c", &c) != EOF) {
    i++;
    if(i % 10 == 0) {
      printf("%c\n", c);
    } else {
      printf("%c", c);
    }
  }
  return 0;
}