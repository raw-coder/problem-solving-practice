#include <stdio.h>
#define N 1000001

int T, L, R;
long long p[N], cp[N];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void init() {
    for(int i = 0; i < N; i++) {
        p[0] = 0;
        cp[0] = 0;
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < i; j++) {
            if(gcd(i, j) == 1) p[i]++;
        }
        cp[i] = cp[i - 1] + p[i];
    }
}

int main() {
    init();

    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &L, &R);
        printf("#%d %d\n", t, cp[R] - cp[L - 1]);
    }
    return 0;
}