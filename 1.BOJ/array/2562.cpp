#include <stdio.h>
int main() {
  int a[10], i;
  int max = -1234567890, idx;
  for(i = 1; i <= 9; i++) {
    scanf("%d", &a[i]);
    if (a[i] > max) {
      max = a[i];
      idx = i;
    }
  }
  printf("%d\n", max);
  printf("%d", idx);
  return 0;
}