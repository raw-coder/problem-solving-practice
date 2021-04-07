#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b;
int in[1001];
int w[1001];
vector<int> edges[1001];
queue<int> q;

int max(int a, int b) {
    return a > b ? a : b;
}

void init() {
    for(int i = 1; i <= N; i++) {
        in[i] = 0;
        w[i] = 1;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    init();
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
        for(int next: edges[from]) {
            in[next]--;
            w[next] = max(w[next], w[from] + 1);
            if(in[next] == 0) {
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        printf("%d ", w[i]);
    }
    return 0;
}