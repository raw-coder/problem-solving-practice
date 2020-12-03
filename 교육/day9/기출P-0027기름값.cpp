#include <stdio.h>

int T, N, L, x, y, c[2001], d[2001], dp[2001][51];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &L);

        
        int ans = 0;
        for(int i = 1; i < N; i++) {
            scanf("%d", &x);
            scanf("%d", &y);
            c[i] = x;
            d[i + 1] = y;
            if(y > L) ans = -1;
        }        
        scanf("%d", &x);
        // printf("#%d ", t);
        // if(ans == - 1) {
        //     printf("-1\n");
        //     continue;
        // }
        for(int i = 1; i <= N; i++) {            
            dp[i][1] = c[i];
            for(int j = 2; j <= L; j++) {
                dp[i][j] = dp[i][j - 1] + c[i];
                // if(j + d[i] <= L) dp[i][j] = min(dp[i -1][j + d[i]], dp[i][j]);
            }
        }

        printf("\n");
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= L; j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }

        printf("%d\n", dp[N][0]);
    }
    return 0;
}