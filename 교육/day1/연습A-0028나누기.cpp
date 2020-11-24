#include <stdio.h>

int mat[129][129];
int zero, one;
int T, N;

bool hasOneColor(int x, int y, int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(mat[x + i][y + j] != mat[x][y]) {
        return false;
      }
    }
  }
  return true;
}

void dnc(int x, int y, int size) {
  // 종료조건
  if(hasOneColor(x, y, size)) {
    if(mat[x][y] == 0) {
      zero++;
    } else {
      one++;
    }
    return;
  }
  // 종료조건 외
  size /= 2;
  dnc(x, y, size);
  dnc(x, y + size, size);
  dnc(x + size, y, size);
  dnc(x + size, y + size, size);
}


int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    zero = 0;
    one = 0;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        scanf("%d", &mat[i][j]);
      }
    }
    dnc(1, 1, N);
    printf("#%d %d %d\n", tc, zero, one);
  }

  return 0;
}