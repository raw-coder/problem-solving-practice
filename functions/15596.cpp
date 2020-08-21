// #include <stdio.h>
long long sum(int *a, int n) {
  int i;
  long long sum = 0;
  for(i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}

// int main() {
//   int a[3000000], i;
//   for(i = 1; i <= 3000000; i++) {
//     a[i] = 1000000;
//   }
//   printf("%lld", sum(a, 3000000));
//   return 0;
// }