#include <stdio.h>
#define SIZE 300000

int T, N, x, a[SIZE + 1], dp[SIZE + 1], ans;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d", &N);

        for(int i = 1; i <= N; i++) {
            scanf("%d", &x);
            a[i] = x;
        }

        ans = 0;

        for(int i = 1; i <= N; i++) {
            dp[i] = 1;
            for(int j = 1; j < i; j++) {
                if(a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        printf("#%d %d\n", t, ans);
    }
}