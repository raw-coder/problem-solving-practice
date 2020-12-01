#include <stdio.h>
#include <queue>
#include <vector>
#define SIZE 100000
#define K 17

using namespace std;

int T, N, Q, x, a, b;
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

void init() {
    for(int i = 1; i <= N; i++) {
        while(!edges[i].empty()) edges[i].pop_back();
    }
    while(!q.empty()) q.pop();
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        init();

        scanf("%d %d", &N, &Q);

        p[0][1] = 0;
        for(int i = 2; i <= N; i++) {
            scanf("%d", &x);
            p[0][i] = x;
            edges[x].push_back(i);
        }

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

        for(int i = 1; i <= K; i++) {
            for(int j = 1; j <= N; j++) {
                p[i][j] = p[i - 1][p[i -1][j]];
            }
        }

        printf("#%d ", t);
        for(int i = 1; i <= Q; i++) {
            scanf("%d %d", &a, &b);
            printf("%d ", depth[a] < depth[b] ? lca(a, b) : lca(b, a));
        }
        printf("\n");
    }
    return 0;
}