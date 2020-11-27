#include <stdio.h>

void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

int main() {
    int a = 10; int b = 20;
    swap(&a, &b);
    printf("%d %d\n", a, b);

    int arr[2] = {0, 1};
    swap(&arr[0], &arr[1]);
    printf("%d %d\n", arr[0], arr[1]);

    return 0;
}