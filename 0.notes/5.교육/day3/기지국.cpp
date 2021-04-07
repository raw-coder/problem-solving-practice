#include <stdio.h>

int T, N, M, B;

int rec(int p, int b) {
    // // condition
    if(p > n || b ==0) return 0;
    if(dp[p][b] > 0) return dp[p][b];

    int sum = 0;
    for(int i = 0; i< m; i++) {
        sum += data[p+i];
    }
    // max(p에 기지국을 세운 경우, p에 기지국을 안세운 경우)
    return dp[p][b] = max(sum + rec(p + m, b - 1), rec(p + 1, b));

}

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc < T; tc++) {

    }
    return 0;
}