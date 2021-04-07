#include <stdio.h>

int T, N, x, size;

int tree[1000001];

void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void push(int n) {
    tree[size++] = n;
}

void rearrange(int index) {
    if(index * 2 + 1 < N && tree[index] < tree[index * 2] && tree[index] < tree[index * 2 + 1]) {
        if(tree[index * 2] > tree[index * 2 + 1]) {
            swap(&tree[index], &tree[index * 2]);
            rearrange(index * 2);
        } else {
            swap(&tree[index], &tree[index * 2 + 1]);
            rearrange(index * 2 + 1);
        }
    } else if(index * 2 < N && tree[index] < tree[index * 2]) {
        swap(&tree[index], &tree[index * 2]);
        rearrange(index * 2);
    } else if(index * 2 + 1 < N && tree[index] < tree[index * 2 + 1]) {
        swap(&tree[index], &tree[index * 2 + 1]);
        rearrange(index * 2 + 1);
    }
}

void pop() {
    tree[1] = tree[--size];
    rearrange(1);
}

int top() {
    return tree[1];
}

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            tree[i] = 0;
        }
        size = 1;

        for(int i = 1; i <= N; i++) {
            scanf("%d", &x);
            push(x);
        }
        
        pop();

        int idx;
        for(idx = 1; idx < N ; idx++) {
            if(tree[idx] == x) break;
        }
        
        int k = 2;
        int depth = 0;
        while(idx > k - 1) {
            k = k << 1;
            depth++;
        }
        int seq = 1;
        for(int i = k >> 1; i < N; i++) {
            if(tree[i] == x) break;
            seq++;
        }

        printf("#%d %d %d\n", tc, depth, seq);
    }
    return 0;
}