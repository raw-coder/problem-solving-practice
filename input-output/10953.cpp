#include <stdio.h>
int main() {
  int T, i, A, B;
  char c[4];
  scanf("%d", &T);
  for(i = 1; i <= T; i++) {
    scanf("%s", c);
    printf("%d\n", (c[0] - '0') + (c[2] - '0'));
  }
  return 0;
}