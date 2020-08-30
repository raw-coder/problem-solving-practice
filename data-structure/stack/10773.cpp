#include <stdio.h>
int a[100001], top = 0;
int pop() {
  return a[top--];
}
void push(int n) {
  a[++top] = n;
}
int main() {
  int K, i, x;
  scanf("%d", &K);
  for(i = 1; i <= K; i++) {
    scanf("%d", &x);
    if(x == 0) {
      pop();
    } else {
      push(x);
    }
  }
  int sum = 0;
  while(top > 0) {
    sum += pop();
  }
  printf("%d", sum);
  return 0;
}