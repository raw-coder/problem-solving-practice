#include <stdio.h>
int main() {
  int H, M, t;
  scanf("%d %d", &H, &M);
  t = H * 60 + M - 45;
  if(t < 0) t += 60 * 24;
  printf("%d %d", t / 60, t - (t / 60) * 60);
  return 0;
}