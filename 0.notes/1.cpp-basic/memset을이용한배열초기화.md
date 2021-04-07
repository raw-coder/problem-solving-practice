### memset 을 이용한 배열 초기화

 for 반복하면서 초기화하는것 보다 미세하게 빠르다


```cpp
#include <stdio.h>
#include <string.h>

#define N 10

using namespace std;

int visited[10];

int main() {
    for(int i = 0; i < N; i++) {
        visited[i] = i;
    }
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; i++) printf("%d ", visited[i]); // 0 0 0 0 0 0 0 0 0 0

    return 0;
}
```