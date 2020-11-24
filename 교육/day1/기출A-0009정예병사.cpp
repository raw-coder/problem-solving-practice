#include <stdio.h>
#include <algorithm>

using namespace std;

struct Sol {
  int a, d;
};

Sol sols[100000];

bool compare(Sol sol1, Sol sol2) {
  return sol1.a < sol2.a;
}

int main() {
  int T, N, a, d;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d %d", &a, &d);
      sols[i].a = a;
      sols[i].d = d;
    }
    sort(sols, sols + N, compare);
    int minD = sols[0].d;
    int sum = 1;
    for(int i = 1; i < N; i++) {
      if(sols[i].d < minD) {
        sum++;
        minD = sols[i].d;
      }
    }
    printf("#%d %d\n", tc, sum);
  }
  return 0;
}

// 정렬
