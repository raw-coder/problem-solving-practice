#include <stdio.h>
#include <algorithm>

using namespace std;

int T, N, x, a[1000000];

int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d", &x);
    x *= 10000000;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + N);

    int start = 0;
    int end = N - 1;
    while(start < end) {
      int sum = a[start] + a[end];
      if(sum == x) break;
      if(sum < x) start++;
      if(sum > x) end--;
    }
    if(start < end) {
      printf("#%d yes %d %d\n", tc, a[start], a[end]);
    } else {
      printf("#%d danger\n", tc);
    }
  }
  return 0;
}