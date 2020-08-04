// TODO

#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b; 
}

int main() {
  int dp[301], s[301] = {0};
  int N, p, i;
  scanf("%d", &N);

  for (i = 1; i <= N; i++) {
    scanf("%d", &p);
    dp[i] = max(dp[i - 1] + p, dp[i - 2] + p)
  }
  return 0;
}