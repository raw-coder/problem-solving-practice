#include <stdio.h>
#include <vector>

using namespace std;

int N, M, i, u, v, cc = 0;
vector<int> e[1001];
int group[1001];

void dfs(int node) {
  group[node] = cc;
  for(int next: e[node]) {
    if(group[next] == -1) dfs(next);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for(i = 1; i <= M; i++) {
    scanf("%d %d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(i = 1; i <= N; i++) {
    group[i] = -1;
  }
  for(i = 1; i <= N; i++) {
    if(group[i] == -1) {
      cc++;
      dfs(i);
    }
  }
  printf("%d", cc);
  return 0;
}