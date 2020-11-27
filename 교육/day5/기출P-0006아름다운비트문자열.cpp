// FIXME

#include <stdio.h>
#define SIZE 1001

typedef long long ll;

int T, N, K;
ll c[SIZE][SIZE], X;

ll pow(ll value, ll n) {
    if(n == 0) return 0;
    if(n == 1) return value;
    ll result = pow(value, n / 2);
    result *= result;
    if(n % 2) result *= value;
    return result;
}

int main() {
    ll limit = pow(2, 60);
    for(int i = 1; i < SIZE; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] = c[i][j] > limit ? limit + 1 : c[i][j];
        }
    }

    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d %lld", &N, &K, &X);
        
        printf("#%d ", t);
        while(N > 0) {
            if(c[N - 1][K] >= X) {
                printf("0");
            } else {
                printf("1");
                X -= c[N  - 1][K];
                K--;
            }
            N--;                
        }
        printf("\n");
    }
    return 0;
}