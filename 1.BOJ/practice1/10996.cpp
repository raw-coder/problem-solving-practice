#include <stdio.h>
int min(int a, int b) {
  return a < b ? a : b;
}
int main() {
  int N, i, j;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    for(j = 1; j <= N - N / 2; j++) {
      printf("* ");
    }
    if(N == 1) continue;
    printf("\n");
    for(j = 1; j <= N / 2; j++) {
      printf(" *");
    }
    printf("\n");
  }
  return 0;
}