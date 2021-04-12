#include <stdio.h>

int w, h, i, j, k, mat[50][50], isVisited[50][50], dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

void dfs(int x, int y) {
  isVisited[x][y] = 1;
  for(k = 0; k < 8; k++) {
    int nextX = x + dx[k];
    int nextY = y + dy[k];
    if(nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) continue;
    if(isVisited[nextX][nextY] == 0 && mat[nextX][nextY] == 1) dfs(nextX, nextY);
  }
}

int main() {
  while(1 == 1) {
    scanf("%d %d", &w, &h);
    if(w == 0 && h == 0) break;
    for(i = 0; i < h; i++) {
      for(j = 0; j < w; j++) {
        scanf("%d", &mat[i][j]);
        isVisited[i][j] = 0;
      }
    }
    int sum = 0;
    for(i = 0; i < h; i++) {
      for(j = 0; j < w; j++) {
        if(mat[i][j] == 1 && isVisited[i][j] == 0) {
          dfs(i, j);
          sum++;
        } 
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}