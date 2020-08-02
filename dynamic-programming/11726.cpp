#include <stdio.h>

int dp[1001];

int main() {
  int i, n;
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (i = 3; i <= 1000; i++) {
    dp[i] = (dp[i - 1] * 2 - 1) % 10007;
  }
  scanf("%d", &n);
  printf("%d", dp[n]);
  return 0;
}

// FIXME