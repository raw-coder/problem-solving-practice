#include <stdio.h>
int main() {
  int N, i, j;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    for(j = 1; j <= i - 1; j++) {
      printf(" ");
    }
    for(j = 1; j <= (N - i) * 2 + 1; j++) {
      printf("*");
    };
    printf("\n");
  }
  for(i = 2; i <= N; i++) {
    for(j = 1; j <= N - i; j++) {
      printf(" ");
    }
    for(j = 1; j <= i * 2 - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}