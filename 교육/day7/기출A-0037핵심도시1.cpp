#include <stdio.h>
#include <vector>
#define N 100000

using namespace std;

int T, V, E, A, B, discovered[N + 1], seq;
bool isCut[N + 1];
vector<int> edges[N + 1];

int min(int a, int b) {
    return a < b ? a : b;
}

int dfs(int node) {
    discovered[node] = seq++;
    int ret = discovered[node];

    int children = 0;
    for(int next: edges[node]) {
        if(!discovered[next]) {
            children++;
            int low = dfs(next);
            if(node != 1 && discovered[node] <= low) {
                isCut[node] = true;
            }
            ret = min(ret, low);
        } else {
            ret = min(ret, discovered[next]);
        }
    }
    if(node == 1) {
        isCut[node] = children > 1;
    }
    return ret;
}

void init() {
    for(int i = 1; i <= V; i++) {
        discovered[i] = 0;
        isCut[i] = false;
        while(!edges[i].empty()) edges[i].pop_back();
    }
    seq = 1;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &V, &E);
        init();
        for(int i = 1; i <= E; i++) {
            scanf("%d %d", &A, &B);
            edges[A].push_back(B);
            edges[B].push_back(A);
        }

        dfs(1);

        int count = 0;
        for(int i = 1; i <= V; i++) {
            if(isCut[i]) count++;            
        }
        printf("#%d %d ", t, count);
        if(count > 0) {
            for(int i = 1; i <= V; i++) {
                if(isCut[i]) printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}