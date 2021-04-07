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