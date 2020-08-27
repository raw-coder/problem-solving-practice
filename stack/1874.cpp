#include <stdio.h>
int a[100001], s = -1;
void push(int n) {
  a[++s] = n;
}
int pop() {
  return a[s--];
}
int top() {
  return a[s];
}
int main() {
  int N, x, i;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%d")
  }
  return 0;
}

// TODO