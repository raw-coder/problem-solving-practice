#include <stdio.h>
int main() {
  int N, i;
  int f[13];
  f[1] = 1;
  for(i = 2; i <= 12; i++) {
    f[i] = f[i - 1] * i;
  }
  scanf("%d", &N);
  printf("%d", f[N]);
  return 0;
}