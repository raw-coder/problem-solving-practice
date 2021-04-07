#include <stdio.h>
int main() {
  int A, B, V, c = 0;
  scanf("%d %d %d", &A, &B, &V);
  printf("%d", ((V - B) / (A - B) * 10 + 5) / 10);
}