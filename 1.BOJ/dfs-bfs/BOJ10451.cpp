#include <stdio.h>
#include <vector>

using namespace std;

int T, N, tc, i, j, x, no[1001], cnt = 0;
vector<int> edges[1001];

void dfs(int node, int num) {
  no[node] = num;
  for(int next: edges[node]) {
    if(no[next] == -1) dfs(next, num);
  }
}

int main() {
  scanf("%d", &T);
  for(tc = 1; tc <= T; tc++) {
    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
      while(!edges[i].empty()) {
        edges[i].pop_back();
      }
      no[i] = -1;
      cnt = 0;
    }

    for(i = 1; i <= N; i++) {
      scanf("%d", &x);
      edges[i].push_back(x);
      edges[x].push_back(i);
    }

    for(i = 1; i <= N; i++) {
      if(no[i] == -1) dfs(i, cnt++);
    }
    printf("%d\n", cnt);
  }
  return 0;
}