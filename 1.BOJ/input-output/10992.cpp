#include <stdio.h>
int main() {
  int N, i, j, s;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    for(j = 1; j <= N - i; j++) {
      printf(" ");
    }
    s = i * 2 - 1;
    for(j = 1; j <= s; j++) {
      printf(j == 1 || j == s || i == N ? "*" : " ");
    }
    printf("\n");
  }
  return 0;
}