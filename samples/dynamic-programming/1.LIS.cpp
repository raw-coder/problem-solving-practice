/*
Longest Increasing Subsequence 최장증가수열
*/

#include <stdio.h>
#define SIZE 300000

int T, N, x, a[SIZE + 1], dp[SIZE + 1], ans;

int max(int a, int b) {
    return a > b ? a : b;
}

int binarySearch(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (dp[mid] < target) { 
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return right;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d", &N);

        for(int i = 1; i <= N; i++) {
            scanf("%d", &x);
            a[i] = x;
        }

        dp[1] = a[1];
        int j = 1;
        for(int i = 2; i <= N; i++) {
            if(dp[j] < a[i]) {
                // lis 누적
                // printf("j+1 -> %d %d\n", j + 1, a[i]);
                dp[j + 1] = a[i];
                j++;
            } else {
                // 기존 lis 대체
                int idx = binarySearch(1, j, a[i]);
                // printf("idx -> %d %d\n", idx, a[i]);
                dp[idx] = a[i];
            }
        }
        printf("#%d %d\n", t, j);
    }
}