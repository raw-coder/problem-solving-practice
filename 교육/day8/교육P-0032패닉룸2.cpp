#include <stdio.h>
#include <vector>
#include <queue>
#define SIZE 500

using namespace std;

struct Node {
    Node(int x, int y, int c): x(x), y(y), c(c) {};
    int x, y, c;
    bool operator<(const Node&n) const {
        return c > n.c;
    }
};

int T, N, M, x;
int mat[SIZE + 1][SIZE + 1], d[SIZE + 1][SIZE + 1], dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
priority_queue<Node> pq;

void dijkstra() {
    d[1][1] = mat[1][1];
    pq.push(Node(1, 1, mat[1][1]));
    while(!pq.empty()) {
        Node current = pq.top(); pq.pop();
        for(int i = 0; i < 4; i++) {
            int nextX = current.x + dx[i];
            int nextY = current.y + dy[i];
            if(nextX < 1 || nextX > N || nextY < 1 || nextY > M) continue;
            if(d[nextX][nextY] > d[current.x][current.y] + mat[nextX][nextY]) {
                d[nextX][nextY] = d[current.x][current.y] + mat[nextX][nextY];
                pq.push(Node(nextX, nextY, d[nextX][nextY]));
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                scanf("%d", &x);
                mat[i][j] = x;
                d[i][j] = __INT_MAX__;
            }
        }

        dijkstra();
        printf("#%d %d\n", t, d[N][M]);
    }
    return 0;
}