#include <stdio.h>
#include <queue>
#include <vector>
#define SIZE 10000
#define K 14

using namespace std;

int T, N, Q, x, h, k;
int p[K + 1][SIZE + 1], depth[SIZE + 1], height[SIZE + 1];
queue<int> q;
vector<int> edges[SIZE + 1];

int max(int a, int b) {
    return a > b ? a : b;
}

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
        for(int i = 1; i <= N; i++) {
            scanf("%d %d", &x, &h);
            p[0][i] = x;
            height[i] = h;
            edges[x].push_back(i);
        }

        q.push(1);
        depth[1] = 1;
        while(!q.empty()) {
            int current = q.front(); 
            q.pop();
            for(int next : edges[current]) {
                height[next] = max(height[next], height[current]);
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
            scanf("%d", &k);
            int common = -1;
            for(int j = 1; j <= k; j++) {
                scanf("%d", &x);
                if (common == -1) {
                    common = x;
                } else {
                    common = depth[common] < depth[x] ? lca(common, x) : lca(x, common);
                }
            }
            printf("%d ", height[common]);
        }
        printf("\n");
    }
    return 0;
}