#include <stdio.h>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    printf("%d\n", gcd(10, 50)); // 10
    printf("%d\n", gcd(12, 15)); // 3
    printf("%d\n", gcd(gcd(12, 15), 60)); // 3   
    return 0;
}