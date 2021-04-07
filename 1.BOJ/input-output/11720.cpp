#include <stdio.h>
int main() {
  int N, i, n;
  int sum = 0;
  char c[101];
  scanf("%d", &N);
  scanf("%s", c);
  for(i = 0; i < N; i++) {
    sum += (c[i] - '0');
  }
  printf("%d", sum);
  return 0;
}