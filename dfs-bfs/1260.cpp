#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V, i, x, y;
vector<int> e[1001];
queue<int> q;
bool isVisited[1001];

void dfs(int cur) {
  isVisited[cur] = true;
  printf("%d ", cur);
  for(int next: e[cur]) {
    if(!isVisited[next]) dfs(next);
  }
}

void bfs(int start) {
  q.push(start);
  isVisited[start] = true;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    printf("%d ", cur);
    for(int next: e[cur]) {
      if(!isVisited[next]) {
        q.push(next);
        isVisited[next] = true;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &V);
  for(i = 1; i <= M; i++) {
    scanf("%d %d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for(i = 1; i <= N; i++) {
    sort(e[i].begin(), e[i].end());
  }
  dfs(V);
  for(i = 1; i <= N; i++) {
    isVisited[i] = false;
  }
  printf("\n");
  bfs(V);
  return 0;
}