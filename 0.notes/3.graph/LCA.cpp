#include <stdio.h>
#include <queue>
#include <vector>
#define SIZE 100000
#define K 17 // 2 ^ 17 = 131072 > 100000

using namespace std;

int N, Q, x, a, b;
int p[K + 1][SIZE + 1], depth[SIZE + 1];
queue<int> q;
vector<int> edges[SIZE + 1];

int lca(int a, int b) {
    for(int k = K; k >= 0; k--) {
        if(depth[a] <= depth[p[k][b]]) {
            b = p[k][b];
        }
    }
    if(a == b) return a;    
    for(int k = K; k >= 0; k--) {
        if(p[k][a] != p[k][b]) {
            a = p[k][a];
            b = p[k][b];
        }
    }
    return p[0][a];
}

void initTree() {
    q.push(1);
    depth[1] = 1;

    while(!q.empty()) {
        int current = q.front(); 
        q.pop();
        for(int next : edges[current]) {
            depth[next] = depth[current] + 1;
            q.push(next);
        }
    }
    for(int k = 1; k <= K; k++) {
        for(int v = 1; v <= N; v++) {
            p[k][v] = p[k - 1][p[k -1][v]];
        }
    }
}

void init() {
    for(int i = 1; i <= N; i++) {
        while(!edges[i].empty()) edges[i].pop_back();
    }
    while(!q.empty()) q.pop();
}

int main() {
    init();

    scanf("%d", &N);

    p[0][1] = 0;
    for(int i = 2; i <= N; i++) {
        scanf("%d", &x);
        p[0][i] = x; // i의 부모 노드
        edges[x].push_back(i);
    }
    
    initTree();
    printf("%d ", depth[1] < depth[2] ? lca(1, 2) : lca(2, 1));
    printf("%d ", depth[6] < depth[7] ? lca(6, 7) : lca(6, 7));
    return 0;
}