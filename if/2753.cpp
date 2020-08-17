#include <stdio.h>
int main() {
  int y, x;
  scanf("%d", &y);
  x = (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) ? 1 : 0;
  printf("%d", x);
  return 0;
}