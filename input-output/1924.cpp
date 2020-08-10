#include <stdio.h>
int main() {
  int x, y, i, j;
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int n = 0;
  scanf("%d %d", &x, &y);
  for (i = 1; i <= x - 1; i++) {
    n += days[i];
  }
  n += y;
  switch(n % 7) {
    case 0: printf("SUN"); break;
    case 1: printf("MON"); break;
    case 2: printf("TUE"); break;
    case 3: printf("WED"); break;
    case 4: printf("THU"); break;
    case 5: printf("FRI"); break;
    case 6: printf("SAT"); break;
  }
  return 0;
}