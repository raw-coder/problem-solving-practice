#include <stdio.h>
int main() {
  int r[42] = {0}, i, a, x, n = 0;
  for(i = 1; i <= 10; i++) {
    scanf("%d", &a);
    x = a % 42;
    if(r[x] == 0) {
      n++;
    }
    r[x]++;
  }
  printf("%d", n);
  return 0;
}