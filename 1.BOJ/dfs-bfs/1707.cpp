#include <stdio.h>
#include <vector>

using namespace std;

int K, V, E, a, b;
int color[20001];
bool hasSameColorAdj;
vector<int> edges[20001];

void init() {
  for(int i = 1; i <= V; i++) {
    color[i] = 0;
    while(!edges[i].empty()) edges[i].pop_back();
  }
  hasSameColorAdj = false;
}

void dfs(int node, int c) {
  color[node] = c;
  for(int next : edges[node]) {
    if (color[next] == 0) {
      dfs(next, c * -1);
    } else if(color[next] == c) {
      hasSameColorAdj = true;
    }
  }
}

int main() {
  scanf("%d", &K);
  for(int i = 1; i <= K; i++) {
    scanf("%d %d", &V, &E);
    for(int j = 1; j <= E; j++) {
      scanf("%d %d", &a, &b);
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    int c = 1;
    for(int j = 1; j <= V; j++) {
      if(color[j] == 0) {
        c *= -1;
        dfs(j, c);
      }
    }
    printf("%s\n", hasSameColorAdj ? "NO" : "YES");
    init();
  }
  return 0;
}