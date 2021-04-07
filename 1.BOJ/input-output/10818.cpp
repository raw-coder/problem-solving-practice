#include <stdio.h>
int max(int a, int b) {
  return a > b ? a : b;
}
int min(int a, int b) {
  return a < b ? a : b;
}
int main() {
  int N, x, i;
  int m = 1234567890, M = -1234567890;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%d", &x);
    m = min(m, x);
    M = max(M, x);
  }
  printf("%d %d", m, M);
  return 0;
}