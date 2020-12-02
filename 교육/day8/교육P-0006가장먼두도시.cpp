#include <stdio.h>
#define SIZE 300
int T, N, x, d[SIZE + 1][SIZE + 1];

int main() {
    scanf("%d", &T); 
    for(int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                scanf("%d", &x);
                d[i][j] = x;
            }
        }
        for(int k = 1; k <= N; k++) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    if(d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];                    
                }
            }
        }
        int max = -1;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                max = max < d[i][j] ? d[i][j] : max;
            }
        }
        printf("#%d %d\n", t, max);
    }
    return 0;
}
