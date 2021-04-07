#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

queue<int> q;
vector<int> v[6];
bool visited[6];

void dfs(int position) {
  printf("%d visit\n", position);
  for(int i = 0; i < v[position].size(); i++) {
    int newPosition = v[position][i];
    if(visited[newPosition]) continue;
    visited[newPosition] = true;
    dfs(newPosition);
  }
}

void bfs(int start) {
  q.push(start);
  visited[start] = true;
  while(!q.empty()) {
    int current = q.front();
    q.pop();
    printf("%d visit\n", current);
    for(int i = 0; i < v[current].size(); i++) {
      int next = v[current][i];
      if(visited[next]) continue;
      visited[next] = true;
      q.push(next);
    }
  }
}

int main() {
  v[1].push_back(2);
  v[1].push_back(3);
  v[2].push_back(5);
  v[2].push_back(4);
  v[3].push_back(2);
  v[3].push_back(4);
  v[4].push_back(1);
  v[4].push_back(5);
  visited[1] = true;
  printf("#### DFS ####\n");
  dfs(1);
  // memset(visited, 0, sizeof(visited));
  for(int i = 0; i < 6; i++) {
    visited[i] = false;
  }
  
  printf("#### BFS ####\n");
  bfs(1);
}