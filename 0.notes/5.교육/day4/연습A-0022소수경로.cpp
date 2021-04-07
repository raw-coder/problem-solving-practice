#include <stdio.h>
#include <queue>
#define MAX_NUMBER 10000

using namespace std;

bool isPrime[MAX_NUMBER];
int visited[MAX_NUMBER];
int T, A, B;
queue<int> q;

int main() {
    scanf("%d", &T);

    for(int i = 2; i < MAX_NUMBER; i++) {
        isPrime[i] = true;
    }
    for(int i = 2; i * i <= MAX_NUMBER; i++) {
        if(!isPrime[i]) continue;
        for(int j = i; i * j < MAX_NUMBER; j++) {
            isPrime[i * j] = false;
        }
    }

    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &A, &B);

        while(!q.empty()) q.pop();
        for(int i = 1; i < MAX_NUMBER; i++) {
            visited[i] = -1;
        }

        q.push(A);
        visited[A] = 0;

        while(!q.empty()) {
            int current = q.front();
            q.pop();
            if(current == B) {
                printf("#%d %d\n", t, visited[current]);
                break;
            }

            for(int i = 1; i <= 1000; i *= 10) {
                for(int j = 0; j <= 9; j++) {
                    int newNum = current - ((current / i) % 10) * i + i * j;
                    if(newNum < 1000 || !isPrime[newNum] || visited[newNum] > -1) continue;
                    visited[newNum] = visited[current] + 1;
                    q.push(newNum);
                }
            }
        }
    }
    return 0;
}