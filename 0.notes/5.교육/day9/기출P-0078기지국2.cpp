// FIXME

#include <stdio.h>
#define CITY 1000
#define BASE 50

typedef long long ll;
int T, N, M, B, x;
int c[CITY + 1], cc[CITY + 1];
ll dp[CITY + 1][BASE + 1];

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d %d", &N, &M, &B);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &x);
            c[i] = x;            
        }
        for(int i = 1; i <= N; i++) {            
            for(int j = i; j <= i + M - 1; j++) {
                dp[i][0] += c[j];
            }
            for(int j = 1; j <= B; j++) {                
                if(i > M) {
                    dp[i][j] = max(dp[i - M][j -1] + dp[i][1], dp[i -1][j]);
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        printf("\n");
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= B; j++) {
                printf("%lld ", dp[i][j]);
            }
            printf("\n");
        }

        printf("#%d %lld\n", t, dp[N][B]);
    }
    return 0;
}