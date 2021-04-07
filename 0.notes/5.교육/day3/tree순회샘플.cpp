#include <stdio.h>

char arr[100];
int size;

// 전위
void traversePreOrder(int node) {
    if(node > size) return;
    // 나
    printf("%d\n", node);
    // 왼쪽
    traversePreOrder(node * 2);
    // 오른쪽
    traversePreOrder(node * 2 + 1);
}

// 중위
void traverseInOrder(int node) {
    if(node > size) return;
    // 왼쪽
    traverseInOrder(node * 2);
    // 나
    printf("%d\n", node);
    // 오른쪽
    traverseInOrder(node * 2 + 1);
}

// 후위
void traversePostOrder(int node) {
    if(node > size) return;
    // 왼쪽
    traversePostOrder(node * 2);
    // 나
    printf("%d\n", node);
    // 오른쪽
    traversePostOrder(node * 2 + 1);
}

int main() {
    arr[1] = 'A';
    arr[2] = 'B';
    arr[3] = 'C';
    arr[4] = 'D';
    arr[5] = 'E';
    arr[6] = 'F';
    arr[7] = 'G';
    arr[10] = 'H';
    size = 10;

    printf("### 전위\n");
    traversePreOrder(1);
    printf("### 중위\n");
    traverseInOrder(1);
    printf("### 후위\n");
    traversePostOrder(1);

    return 0;
}