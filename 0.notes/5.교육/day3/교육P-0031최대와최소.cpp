#include <stdio.h>
#define MAX_SIZE 100000
#define MIN_NUMBER -1
#define MAX_NUMBER 10001

using namespace std;

int T, N, Q, x, q, a, b, minSum, maxSum;

int maximum(int a, int b) {
    return a > b ? a : b;
}

int minimum(int a, int b) {
    return a < b ? a : b;
}

struct Node {
    Node():max(MIN_NUMBER), min(MAX_NUMBER) {}
    Node(int max, int min):max(max), min(min) {}
    int max, min;
};

Node tree[MAX_SIZE * 4];

void update(int index, int left, int right, int target, int value) {
    if(left > target || right < target) return;
    if(left == right) {
        tree[index] = Node(value, value);
        return;
    }

    int mid = (left + right) >> 1;
    update(index * 2, left, mid, target, value);
    update(index * 2 + 1, mid + 1, right, target, value);

    tree[index] = Node(
        maximum(tree[index * 2].max, tree[index * 2 + 1].max), 
        minimum(tree[index * 2].min, tree[index * 2 + 1].min)
    );
}

int queryMax(int index, int left, int right, int queryLeft, int queryRight) {
    if(left > queryRight || right < queryLeft) return MIN_NUMBER;
    if(queryLeft <= left && right <= queryRight) return tree[index].max;
    
    int mid = (left + right) >> 1;
    return maximum(queryMax(index * 2, left, mid, queryLeft, queryRight), 
        queryMax(index * 2 + 1, mid + 1, right, queryLeft, queryRight));
}

int queryMin(int index, int left, int right, int queryLeft, int queryRight) {
    if(left > queryRight || right < queryLeft) return MAX_NUMBER;
    if(queryLeft <= left && right <= queryRight) return tree[index].min;

    int mid = (left + right) >> 1;
    return minimum(queryMin(index * 2, left, mid, queryLeft, queryRight), 
        queryMin(index * 2 + 1, mid + 1, right, queryLeft, queryRight));
}

void init() {
    minSum = 0;
    maxSum = 0;
    for(int i = 1; i < MAX_SIZE * 4; i++) {
        tree[i] = Node(MIN_NUMBER, MAX_NUMBER);
    }
}

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &N, &Q);

        init();

        for(int i = 1; i <= N; i++) {
            scanf("%d", &x);
            update(1, 1, N, i, x);
        }
        
        for(int i = 1; i <= Q; i++) {
            scanf("%d %d %d", &q, &a, &b);
            if(q == 0) {
                maxSum += queryMax(1, 1, N, a, b);
                minSum += queryMin(1, 1, N, a, b);
            } else {
                update(1, 1, N, a, b);
            }
        }
        printf("#%d %d %d\n", tc, maxSum, minSum);
    }
    return 0;
}