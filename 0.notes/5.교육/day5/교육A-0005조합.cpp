#include <stdio.h>

int Q, n, k;
int c[5001][5001];

int main() {
    for(int i = 1; i <= 5000; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i -1][j]) % 1000000007;
        }
    }

    scanf("%d", &Q);
    for(int q = 1; q <= Q; q++) {
        scanf("%d %d", &n, &k);
        printf("#%d %d\n", q, c[n][k]);
    }
    return 0;
}