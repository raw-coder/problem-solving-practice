#include <stdio.h>
int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  if (a > 0) {
    printf("%d", b > 0 ? 1 : 4);
  } else {
    printf("%d", b > 0 ? 2 : 3);
  }
  return 0;
}