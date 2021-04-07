#include <stdio.h>

int T, N, H;
int a[100000], b[100000];
int ca[500001], cb[500001], cnt[500001];

int min(int a, int b) {
  return a < b ? a : b;
}

void init() {
  for(int i = 1; i <= H; i++) {
    ca[i] = 0;
    cb[i] = 0;
  }
}

int main() {
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    scanf("%d %d", &N, &H);
    
    init();
    
    for(int i = 0; i < N/2; i++) {
      scanf("%d", &a[i]);
      scanf("%d", &b[i]);
      ca[a[i]]--;
      cb[H-b[i]]++;
    }
    int minCnt = N + 1;
    cnt[0] = N / 2;
    for(int i = 1; i <= H; i++) {
      cnt[i] = cnt[i - 1] + ca[i] + cb[i]; 
      minCnt = min(minCnt, cnt[i]);
    }
    int ans = 0;
    for(int i = 1; i <= H; i++) {
      if(cnt[i] == minCnt) ans++;
    }
    printf("#%d %d %d\n", tc, minCnt, ans);
  }
  return 0;
}