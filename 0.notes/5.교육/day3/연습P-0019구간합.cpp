#include <stdio.h>
#define MAX_SIZE 100000

typedef long long ll;

ll tree[MAX_SIZE * 4];
int T, N, Q, o, x, y, ans;

// index : node index
// left, right : node 가 커버하는 범위
// target : 변경하려는 index
// value : 변경하려는 값
void update(int index, int left, int right, int target, int value) {
    // 범위 벗어난 경우
    if(target < left || right < target) return;
    // leaf 도착
    if(left == right) {
        tree[index] = value;
        return;
    }
    // 내려가는 중
    int mid = (left + right)  >> 1;
    update(index * 2, left, mid, target, value);
    update(index * 2 + 1, mid + 1, right, target, value);
    // 값 update
    tree[index] = (tree[index * 2] + tree[index * 2 + 1]) % 1000000007;
}

ll query(int index, int left, int right, int queryLeft, int queryRight) {
    // 범위 벗어난 경우
    if(left > queryRight || right < queryLeft) return 0;
    // 범위 포함하는 경우
    if(queryLeft <= left && right <= queryRight) return tree[index];
    // 범위 일부 겹치는 경우
    int mid = (left + right)  >> 1;
    return (query(index * 2, left, mid, queryLeft, queryRight) + 
    query(index * 2 + 1, mid + 1, right, queryLeft, queryRight)) % 1000000007;
}


void init() {
    ans = 0;
    for(int i = 0; i < MAX_SIZE * 4; i++) tree[i] = 0;
}

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &N, &Q);
        init();
        for(int i = 1; i <= N; i++) {
            update(1, 1, N, i, i);
        }
        for(int i = 1; i <= Q; i++) {
            scanf("%d %d %d", &o, &x, &y);
            if(o == 0) {
                update(1, 1, N, x, y);
            } else {
                ans = (ans + query(1, 1, N, x, y)) % 1000000007;
            }

        }
        printf("#%d %d\n", tc, ans < 0 ? ans + 1000000007 : ans);
    }
}