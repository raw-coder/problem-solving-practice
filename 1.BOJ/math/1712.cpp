#include <stdio.h>
int main() {
  int A, B, C, x;
  scanf("%d %d %d", &A, &B, &C);
  printf("%d", C > B ? (int)((double)A / (C - B) + 1) : -1);
  return 0;
}