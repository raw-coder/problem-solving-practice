#include <stdio.h>
#include <vector>
#include <queue>
#define V 50000
#define K 16

using namespace std;

int N, M, a, b;
int p[K + 1][V + 1], depth[V + 1];
vector<int> edges[V + 1];
bool visited[V + 1];

queue<int> q;

void initTree() {
    q.push(1);
    depth[1] = 1;
    visited[1] = true;

    while(!q.empty()) {
        int current = q.front(); q.pop();
        for(int next: edges[current]) {            
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
            p[0][next] = current;
            depth[next] = depth[current] + 1;
        }        
    }

    for(int k = 1; k <= K; k++) {
        for(int v = 1; v <= N; v++) {
            p[k][v] = p[k-1][p[k-1][v]];
        }
    }
}

int lca(int a, int b) {
    for(int k = K; k >= 0; k--) {
        if(depth[a] <= depth[p[k][b]]) b = p[k][b];
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

void init() {
    for(int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N - 1; i++) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    initTree();

    scanf("%d", &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", depth[a] < depth[b] ? lca(a, b) : lca(b, a));
    }

    return 0;
}