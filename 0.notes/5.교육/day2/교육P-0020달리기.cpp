#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node {
  int rank;
  int index;
  int change;
};

bool compare(Node a, Node b) {
  a.change++;
  return a.rank > b.rank;
}

int T, N;
Node A[100001];

int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &A[i].rank);
      A[i].index = i;
      A[i].change = 0;
    }

    sort(A, A + N, compare);

    int ans = 0;
    for(int i = 0; i < N; i++) {
      printf("%d %d %d %d\n", i, A[i].index, A[i].rank, A[i].change);
      if(i < A[i].index) {
        ans += A[i].index - i; 
      }
    }

    printf("#%d %d\n", tc, ans);
  }
  return 0;
}