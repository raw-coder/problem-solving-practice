#include <stdio.h>

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int c[1000001];
  int N, i;

  scanf("%d", &N);

  for(i = 2; i <= 1000000; i++) {
    if (i % 3 == 0) {
      c[i] = min(c[i / 3], c[i - 1]) + 1;
    } else if (i % 2 == 0) {
      c[i] = min(c[i / 2],  c[i - 1]) + 1;
    } else {
      c[i] = c[i - 1] + 1;
    }
  }

  printf("%d", c[N]);

  return 0;
}