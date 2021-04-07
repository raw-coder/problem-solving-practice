#include <stdio.h>

int T, N, K, start, end;
int n[1000000], c[1000000];
int words;
int minLength;

int min(int a, int b) {
  return a < b ? a : b;
}

void init() {
  for(int i = 0; i < N; i++) {
    c[i] = 0;
  }
  words = 0;
  minLength = N + 1;
  start = 0;
  end = -1;
}

void solve() {
  while(end < N) {
    if(words == K) {
      minLength = min(minLength, end - start + 1);
      c[n[start]]--;
      if(c[n[start]] == 0) {
        words--;
      }
      start++;
    } else {
      end++;
      c[n[end]]++;
      if(c[n[end]] == 1) {
        words++;
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
      scanf("%d", &n[i]);
    }

    init();

    solve();

    printf("#%d %d\n", tc, minLength == N ? -1 : minLength);
  }
  return 0;
}