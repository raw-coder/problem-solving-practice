// // k = 1 + (k - 1)  = 2 + (k - 2) = 3 + (k - 3) = (k - 3) + 3

#include <stdio.h>

int main() {
  int c[12];
  int T, i, n;
  c[1] = 1;
  c[2] = 2;
  c[3] = 4;
  for (i = 4; i <= 11; i++) {
    c[i] = c[i - 1] + c[i - 2] + c[i - 3];
  }
  scanf("%d", &T);
  for(i = 1; i <= T; i++) {
    scanf("%d", &n);
    printf("%d\n", c[n]);
  }
  return 0;
}