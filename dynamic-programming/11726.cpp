#include <stdio.h>
int dp[1001];
int main() {
  int i, n;
  dp[1] = 1;
  dp[2] = 2;
  for (i = 3; i <= 1000; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
  }
  scanf("%d", &n);
  printf("%d", dp[n]);
  return 0;
}