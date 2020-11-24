#include <stdio.h>
#include <queue>

using namespace std;

struct Node {
  int x, y;
};

queue<Node> q;
int T, N, R, C, U, L;
int visited[201][201];
int offset[8][2] = {{2, 1}, {1, 2} ,{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int bfs(Node n, int limit) {
  q.push(n);
  visited[n.x][n.y] = 0;
  while(!q.empty()) {
    Node current = q.front();
    q.pop();
    if(current.x == U && current.y == L) {
      return visited[U][L];
    }
    for(int i = 0; i < 8; i++) {
      for(int j = 1; j < limit; j++) {
        int nx = current.x + offset[i][0] * j;
        int ny = current.y + offset[i][1] * j;
        if(nx > 0 && ny > 0 && nx <= N && ny <= N && visited[nx][ny] < 0 ) {
          Node newNode;
          newNode.x = nx;
          newNode.y = ny;
          q.push(newNode);
          visited[nx][ny] = visited[current.x][current.y] + 1;
        }
      }
    }
  }
  return 0;  
}

void init() {
  for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        visited[i][j] = -1;
      }
    }
    while(!q.empty()) {
      q.pop();
    }
}

int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d %d %d %d %d", &N, &R, &C, &U, &L);
    
    init();

    Node k;
    k.x = R;
    k.y = C;
    int kc = bfs(k, 2);

    init();

    Node u;
    u.x = R;
    u.y = C;
    int uc = bfs(u, 4);

    printf("#%d %d\n", tc, kc - uc);
  }
  return 0;
}