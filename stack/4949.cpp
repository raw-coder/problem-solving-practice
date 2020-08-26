#include <stdio.h>
int s = 0;
char a[101];
void push(char c) {
  a[++s] = c;
}
char pop() {
  return a[s--];
}
char top() {
  return a[s];
}
int main() {
  char c, a[101];

  while(scanf("%c", &c) != -1) {
    if(c == '.') {
      printf("%s\n", s == 0 ? "yes" : "no");
      s = 0;
    };
    if(c == '(' or c == '[') {
      push(c);
    } else if(c == ')') {
      if(top() == '(') {
        pop();
      } else {
        push(c);
      }
    } else if(c == ']') {
      if(top() == '[') {
        pop();
      } else {
        push(c);
      }
    }
  }
  return 0;
}