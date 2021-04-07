#include <stdio.h>

int T, N, sum, maxSum;
bool visited[11];
int mat[11][11];

void dfs(int index, int depth) {
  sum += mat[depth][index];
  visited[index] = true;
  // printf("%d %d %d\n", index, depth, sum);

  for(int i = 1; i <= N; i++) {
    if(visited[i]) continue;
    dfs(i, depth + 1);
  }
  
  if(depth == N && maxSum < sum) {
    maxSum = sum;
  }

  sum -= mat[depth][index];
  visited[index] = false;
} 

int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        scanf("%d", &mat[i][j]);
      }
    }
    maxSum = -1;
    sum = 0;
    dfs(0, 0);
    printf("#%d %d\n", tc, maxSum);

  }
  return 0;
}