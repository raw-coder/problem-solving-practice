#include <stdio.h>
#include <vector>
#include <queue>
#define V 40000
#define K 16
using namespace std;

int p[K + 1][V + 1], depth[K + 1];
int M, N, a, b, c;
vector<int> edges[K + 1];
queue<int> q;

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N -1; i++) {
    scanf("%d %d %d", &a, &b, &c);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) {
    depth[i] = 0;
  }

  q.push(1);
  depth[1] = 1;
  while(!q.empty()) {
    int current = q.front(); q.pop();
    for(int next : edges[current]) {
      if(depth[next] == 0) continue;
      q.push(next);
      depth[next] = depth[current] + 1;
    }
  }


}