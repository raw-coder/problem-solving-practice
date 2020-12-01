// FIXME

#include <stdio.h>

#define N 4196 // 2 ^ 12
#define M 100000123

long long c[N][N], ans[12];
int T, x;

int main() {
    for(int i = 1; i < N; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
        }
    }

    ans[1] = 2;
    for(int i = 2; i <= 11; i++) {
        int numbers = 1;
        for(int j = 1; j <= i + 1; j++) {
            numbers *= 2;
        }
        numbers -= 2;
        
        ans[i] = c[numbers][numbers / 2];
        ans[i] = (ans[i] * ans[i - 1]) % M;
        ans[i] = (ans[i] * ans[i - 1]) % M;

        printf("%d %lld = %d %lld %lld\n", i, ans[i], numbers, c[numbers][numbers / 2] , ans[i - 1]);

    }

    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d", &x);
        printf("#%d %lld\n", t, ans[x]);
    }
    return 0;
}