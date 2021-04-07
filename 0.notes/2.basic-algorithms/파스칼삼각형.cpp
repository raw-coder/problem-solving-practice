#include <stdio.h>

long long pas[100][100];

int main() {
    for(int i = 1; i < 100; i++) {
        pas[i][0] = pas[i][i] = 1;
        for(int j = 1; j < i; j++) {
            pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
        }
    }
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j <= i; j++) {
            printf("%lld ", pas[i][j]);
        }
        printf("\n");
    }
    return 0;
}