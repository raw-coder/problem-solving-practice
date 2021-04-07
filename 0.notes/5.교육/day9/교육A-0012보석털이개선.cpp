// FIXME : dp 1차원 배열로도 되나?

#include <stdio.h>

typedef long long ll;

int T, N, M, a, b, w[1001], c[1001];
ll dp[10001];

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
        printf("\n");
        for(int i = 1; i <= N; i++) {
            for(int j = M; j >= 0; j--) {
                if(j >= w[i]) {
                    dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
                }
                printf("%d ", dp[j]);
            }
            printf("\n");
        }

        printf("#%d %lld\n", t, dp[M]);
    }
    return 0;
}