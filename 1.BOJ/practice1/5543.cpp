#include <stdio.h>
int min(int a, int b) {
  return a < b ? a : b;
}
int main() {
  int a, b, c, x, y;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &x);
  scanf("%d", &y);
  printf("%d", min(min(a, b), c) + min(x, y) - 50);
  return 0;
}