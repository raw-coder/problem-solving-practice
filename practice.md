```
int binary_search(int a[], int length, int targe) {
  int left = 0;
  int right = length - 1;
  int mid = 0;
  while (left < right) {
    mid = (left + right) >> 1;
    if(a[mid] === targe) {
      return mid;
    } else if (targe < a[mid]) {
      right = mid
    }
  }
}
```