#include <stdio.h>
long long pow(long long value, long long n) {
  if(n == 1) return value;
  if(n == 0) return 1;
  long long result = pow(value, n / 2);
  result *= result;
  if(n % 2) result *= value;
  return result;
}

int main() {
  printf("%lld", pow(2, 6000000));
  return 0;
}