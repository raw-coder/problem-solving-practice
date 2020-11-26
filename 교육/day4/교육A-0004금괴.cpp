#include <stdio.h>

int T, N, M, ans;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);

        int g = gcd(N, M);

        printf("#%d %d\n", t, (M/g - 1) * g);
    }
    return 0;
}