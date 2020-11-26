#include <stdio.h>
#include <vector>

using namespace std;

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
  dfs(1);
}