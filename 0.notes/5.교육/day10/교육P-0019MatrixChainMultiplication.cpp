// FIXME
#include <stdio.h>
#define SIZE 500

int min(int a, int b) {
  return a < b ? a : b;
}

int T, n, x, a[SIZE + 2], dp[SIZE + 2][SIZE + 2];

int solve(int start, int end) {
  if(start == end) return 0;
  if(dp[start][end] != -1) return dp[start][end];

  int ret = __INT_MAX__;
  for(int i = start; i < end; i++) {
    ret = min(ret, solve(start, i) + solve(i + 1, end) + a[i] * a[i + 1] * a[i + 1]);
  }
  dp[start][end] = ret;
  return ret;
}

void init() {
  for(int i = 1; i <= n + 1; i++) {
    for(int j = 1; j <= n + 1; j++) {
      dp[i][j] = -1;
    }
  }
}

int main() {
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    scanf("%d", &n);
    init();
    for(int i = 1; i <= n + 1; i++) {
      scanf("%d", &x);
      a[i] = x;
    }
    printf("\n");
    solve(1, n);
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j <= n + 1; j++) {
          printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
  }
  return 0;
}