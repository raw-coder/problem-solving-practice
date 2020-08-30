// fixme : vector 이용하여 수정
#include <stdio.h>
int a[100001], s = 0;
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
  int N, x, i, idx = 1, ridx = 1;
  char r[100001];
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    push(i);
    scanf("%d", &x);
    if()
  }
  return 0;
}