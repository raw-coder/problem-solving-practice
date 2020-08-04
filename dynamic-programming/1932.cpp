// TODO
#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int N, i, j, p, max;
  int t[501][501];
  int dp[501];
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    for(j = 1; j <= i; j++) {
      scanf("%d", &t[i][j]);
      dp[i][j] = max(t[i - 1][j - 1], t[i - 1])
    }
    printf("\n");
  }
  return 0;
}