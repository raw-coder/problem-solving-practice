#include <stdio.h>
#define SIZE 1000

int T, N, M, x, a[SIZE + 1][SIZE + 1], dp[SIZE + 1][SIZE + 1], ans;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        ans = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                scanf("%d", &x);
                a[i][j] = 1 - x;
                dp[i][j] = a[i][j] > 0 ? min(min(dp[i -1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + a[i][j] : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        printf("#%d %d\n", t, ans);
    }
    return 0;
}