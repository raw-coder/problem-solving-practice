#include <stdio.h>
#include <vector>

using namespace std;

int T, N, i, j, x;
int c1[9], c2[9], c3[9]; // card 정보
int s[9][37]; // score
int isVisited[37]; // card 사용 여부
vector<int> cards; // 남은 card

void dfs(int node) {
  isVisited[node] = 1;
  for(int next: cards) {
    if(isVisited[next] == 0) dfs(next);
  }
  isVisited[node] == 0;
}

int main() {
  scanf("%d", &T);
  for(i = 1; i <= T; i++) {
    // init
    for(j = 1; j <= 4 * N; j++) {
      isVisited[j] = 0;
      cards.clear();
    }
    // card input
    scanf("%d", &N);
    for(j = 1; j <= N; j++) {
      scanf("%d", &x);
      c1[j] = x;
      isVisited[x] = 1;
    }
    for(j = 1; j <= N; j++) {
      scanf("%d", &x);
      c2[j] = x;
      isVisited[x] = 1;
    }
    for(j = 1; j <= N; j++) {
      scanf("%d", &x);
      c3[j] = x;
      isVisited[x] = 1;
    }
    for(j = 1; j <= N * 4; j++) {
      if(!isVisited[j]) cards.push_back(j);
    }

    // solve
    printf("#%d ", i);
    for(j = 1; j <= N; j++) {
      printf("%d ", cards[j]);
    }
    printf("\n");
  }
  return 0;
}