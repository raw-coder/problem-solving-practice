#include <stdio.h>

typedef long long ll;

int T, N, M, a, b, w[1001], c[1001];
ll dp[1001][10001];

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        for(int i = 1; i<= N; i++) {
            scanf("%d %d", &a, &b);
            c[i] = a;
            w[i] = b;
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(j < w[i]) {
                    dp[i][j] = dp[i -1][j];
                } else {
                    dp[i][j] = max(dp[i -1][j], dp[i - 1][j - w[i]] + c[i]);
                }
            }
        }
        printf("#%d %lld\n", t, dp[N][M]);
    }
    return 0;
}