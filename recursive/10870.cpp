#include <stdio.h>
int f[21], N, i;
int fib(int n) {
  return f[n - 1] + f[n - 2];
}
int main() {
  f[0] = 0;
  f[1] = 1;
  for(i = 2; i <= 20; i++) {
    f[i] = fib(i);
  }
  scanf("%d", &N);
  printf("%d", f[N]);
  return 0;
}