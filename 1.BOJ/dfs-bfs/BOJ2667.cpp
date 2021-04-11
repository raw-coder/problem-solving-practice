#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sizes;
int N, arr[25][25], isVisited[25][25] = {0}, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, i, j, k;

int dfs(int x, int y) {
  isVisited[x][y] = 1;
  int sum = 0;
  for(int k = 0; k < 4; k++) {
    int nextX = x + dx[k];
    int nextY = y + dy[k];
    if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && arr[nextX][nextY] == 1 && isVisited[nextX][nextY] == 0 ) sum += dfs(nextX, nextY);
  }
  return sum + 1;
}

int main() {
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }

  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      if(arr[i][j] == 1 && isVisited[i][j] ==0) {
        sizes.push_back(dfs(i, j));
      } 
    }
  }

  printf("%lu\n", sizes.size());
  sort(sizes.begin(), sizes.end());
  for(int size : sizes) {
    printf("%d\n", size);
  }
  return 0;
}