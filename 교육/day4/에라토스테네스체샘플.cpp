#include <stdio.h>
#define N 10001

bool prime[N];
int i, j;


int main() {
    for(i = 2; i * i < N; i++) {
        if(!prime[i]) {
            for(j = 2; i * j < N; j++) prime[i * j] = true;
        }
    }
    for(i = 2; i < N; i++) {
        if(!prime[i]) printf("%d, ", i);
    }
    return 0;
}