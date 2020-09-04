#include <stdio.h>
int dp[101][10] = {{0},{0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };
int div = 1000000000;

int f(int n, int d) {
  if(dp[n][d] > 0 || n == 1) return dp[n][d];
  if(d == 0) {
    dp[n][d] = f(n - 1, 1) % div;
  } else if(d == 9) {
    dp[n][d] = f(n - 1, 8) % div;
  } else {
    dp[n][d] = (f(n - 1, d - 1) + f(n - 1, d + 1)) % div;
  }
  return dp[n][d];
}

int main() {
  int N, i;
  long sum = 0;
  scanf("%d", &N);
  for(i = 0; i <= 9; i++) {
    sum += f(N, i);
  }  
  printf("%ld", sum % div);
  return 0;
}