#include <stdio.h>

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int dp[1001][3] = {0};
  int N, i, r, g, b;

  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d %d %d", &r, &g, &b);
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b;
  }
  printf("%d", min(min(dp[N][0], dp[N][1]), dp[N][2]));
  return 0;
}