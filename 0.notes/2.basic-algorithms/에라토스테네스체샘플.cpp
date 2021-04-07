// FIXME:

#include <stdio.h>
#define N 10001

bool isNotPrime[N];
int i, j;


int main() {
    for(i = 2; i * i < N; i++) {
        if(!isNotPrime[i]) {
            for(j = 2; i * j < N; j++) isNotPrime[i * j] = true;
        }
    }
    for(i = 2; i < N; i++) {
        if(!isNotPrime[i]) printf("%d, ", i);
    }
    return 0;
}