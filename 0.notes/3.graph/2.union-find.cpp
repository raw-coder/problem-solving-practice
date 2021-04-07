#include <stdio.h>
#define N 5

int parent[N + 1];

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void _union(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

void init() {
    for(int i = 1; i <= N; i++) parent[i] = i;
}

int main() {
    init();
    
    _union(1, 3);
    _union(4, 5);
    
    printf("%d\n", find(3)); // 1
    printf("%d\n", find(5)); // 4

    _union(5, 3);

    printf("%d\n", find(5)); // 1

    
    return 0;
}