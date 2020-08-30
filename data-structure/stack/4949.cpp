#include <stdio.h>
int s = 0;
char a[102];
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
  char c;
  int isInput = 0;

  while(scanf("%c", &c) != -1) {
    if(c == '.') {
      if(isInput == 0) break;
      printf("%s\n", s == 0 ? "yes" : "no");
      s = 0;
      isInput = 0;
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
    } else {
      isInput = 1;
    }
  }
  return 0;
}