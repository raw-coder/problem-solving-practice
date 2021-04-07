#include <stdio.h>
#include <vector>
#include <queue>
#define V 40000
#define K 16
using namespace std;

struct Edge {
  Edge(int to, int cost): to(to), cost(cost) {}
  int to, cost;
};

int p[K + 1][V + 1], depth[V + 1], dis[V + 1];
int M, N, a, b, c;
vector<Edge> edges[V + 1];
queue<int> q;
bool visited[V + 1];

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

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N -1; i++) {
    scanf("%d %d %d", &a, &b, &c);
    edges[a].push_back(Edge(b, c));
    edges[b].push_back(Edge(a, c));
  }

  for(int i = 1; i <= N; i++) {
    visited[i] = false;
    depth[i] = 0;
  }

  q.push(1);
  depth[1] = 1;
  dis[1] = 0;
  visited[1] = true;
  while(!q.empty()) {
    int current = q.front(); q.pop();
    for(Edge e : edges[current]) {      
      int next = e.to;
      if(visited[next]) continue;
      q.push(next);
      depth[next] = depth[current] + 1;
      p[0][next] = current;
      dis[next] = dis[current] + e.cost;
      visited[next] = true;
    }
  }
  for(int k = 1; k <= K; k++) {
    for(int v = 1; v <= N; v++) {
      p[k][v] = p[k-1][p[k-1][v]];
    }
  }

  scanf("%d", &M);
  for(int i = 1; i <= M; i++) {
    scanf("%d %d", &a, &b);
    int node = depth[a] < depth[b] ? lca(a, b) : lca(b, a);
    printf("%d\n", dis[a] + dis[b] - dis[node] * 2);
  }
  return 0;
}