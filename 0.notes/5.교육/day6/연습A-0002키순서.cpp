#include <stdio.h>
#include <vector>
#define SIZE 500

using namespace std;

vector<int> edges[SIZE + 1], reverseEdges[SIZE + 1];
int parent[SIZE + 1], children[SIZE + 1];
bool visited[SIZE + 1];
int T, N, M, a, b, ans;
int mat[SIZE + 1][SIZE + 1];

void init() {
    for(int i = 1; i <= SIZE; i++) {
        parent[i] = children[i] = 0;
        while(!edges[i].empty()) edges[i].pop_back();
        for(int j = 1; i <= SIZE; j++) {
            mat[i][j] = 0;
        }
    }
    ans = 0;
}

void dfs(int node) { 
    parent[node]++;   
    for(int next: edges[node]) {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next);
        visited[next] = false;
    }
}

void initVisited() {
    for(int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= M; i++) {
            scanf("%d %d", &a, &b);
            edges[a].push_back(b);            
            reverseEdges[b].push_back(a);
        }

        for(int i = 1; i <= N; i++) {
            for(int j  = 1; j <= N; j++) {
                for(int k = 1; k <= N; k++) {
                    
                }
            }
        }

        for(int i = 1; i <= N; i++) {
            printf("- %d %d\n", i, parent[i]);
        }

        printf("#%d %d", t, ans);
    }
    return 0;
}