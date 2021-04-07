#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Block {
  int s, c;
};

Block blocks[100];
int scores[21];

int T, N, K;

bool compare(Block b1, Block b2) {
  return b1.s > b2.s;
}

int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
      scanf("%d", &blocks[i].s);
    }
    for(int i = 0; i < N; i++) {
      scanf("%d", &blocks[i].c);
    }
    for(int i = 1; i <= K; i++) {
      scores[i] = 0;
    }
    sort(blocks, blocks + N, compare);
    for(int i = 0; i < N; i++) {
      Block b = blocks[i];
      int index = b.c;
      while(index > 0) {
        if(scores[index] == 0) {
          scores[index] = b.s;
          break;
        }
        index--;
      }
    }
    int sum = 0;
    for(int i = 1; i <= K; i++) {
      sum += scores[i];
    }
    printf("#%d %d", tc, sum);
  }
  return 0;
}