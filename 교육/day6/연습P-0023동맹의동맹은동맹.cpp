#include <stdio.h>
#define SIZE 100000

int T, N, Q, x, a, b, sum;
int parent[SIZE + 1];

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void _union(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x < y) {
        parent[y] = x;  
    } else {
        parent[x] = y;
    }
}

void init() {
    sum = 0;
    for(int i = 1; i <= N; i++) parent[i] = i;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d", &N);
        init();
        scanf("%d", &Q);
        for(int i = 1; i <= Q; i++) {
            scanf("%d %d %d", &x, &a, &b);
            if(x == 0) {
                _union(a, b);
            } else {
                if(find(a) == find(b)) sum++;
            }
        }
        printf("#%d %d\n", t, sum);
    }
    return 0;
}