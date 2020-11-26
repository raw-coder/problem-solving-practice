#include <stdio.h>
#include <vector>
#define MAX_NUMBER 1000001

using namespace std;

int T, L, R;

long long p[MAX_NUMBER], cp[MAX_NUMBER] = {0, 1};

int main() {
    for(int i = 1; i < MAX_NUMBER; i++) {
        p[i] = i;
    }
    for(int i = 2; i < MAX_NUMBER; i++) {
        if(p[i] == i) {
            for(int j = i; j < MAX_NUMBER; j += i) {
                p[j] -= p[j] / i;
            }
        }
        cp[i] = cp[i - 1] + p[i];
        
    }
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &L, &R);
        printf("#%d %lld\n", t, cp[R] - cp[L - 1]);
    }
    return 0;
}