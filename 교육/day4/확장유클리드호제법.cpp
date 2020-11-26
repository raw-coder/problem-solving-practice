#include <stdio.h>

int TC, x, y, z, s0, s1, t0, t1, q, r0, r1, T;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &TC);
    for(int t = 1; t <= TC; t++) {
        scanf("%d %d %d", &x, &y, &z);
        if(z%gcd(x, y)) {
            printf("#%d -1\n", t);
            continue;
        }
        s0 = t1 = 1;
        s1 = t0 = 0;
        r0 = x;
        r1 = y;
        while(r1) {
            q = r0 /r1;
            T = r0;
            r0 = r1;
            r1 = T - r1 * q;
            T = s0;
            s0 = s1;
            s1 = T - s1 * q;
            T = t0;
            t0 = t1;
            t1 = T - t1 * q;
        }
        q = z / gcd(x, y);
        printf("#%d %d %d\n", t, s0 * q, t0 * q);
    }
    return 0;
}