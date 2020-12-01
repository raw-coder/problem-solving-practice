#include <stdio.h>
#include <queue>
#include <vector>
#define SIZE 32000

using namespace std;

int N, M, a, b;
int in[SIZE + 1];
vector<int> edges[SIZE + 1];
queue<int> q;

void init() {
    for(int i = 1; i <= SIZE; i++) in[i] = 0;
}

int main() {
    init();
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        in[b]++;
    }
    for(int i = 1; i <= N; i++) {
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int from = q.front(); q.pop();
        printf("%d ", from);
        for(int to: edges[from]) {
            in[to]--;
            if(in[to] == 0) q.push(to);
        }
    }
    return 0;
}