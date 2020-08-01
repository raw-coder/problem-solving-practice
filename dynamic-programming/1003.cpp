#include <stdio.h>

int dp[41][2];

int main() {
  int T, N, i;

  dp[0][0] = 1;
  dp[0][1] = 0;
  dp[1][0] = 0;
  dp[1][1] = 1;
  for(i = 2; i <= 40; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
    dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
  }

  scanf("%d", &T);
  for(i = 1; i <= T; i++) {
    scanf("%d", &N);
    printf("%d %d\n", dp[N][0], dp[N][1]);
  }
  return 0;
}