#include <stdio.h>
#include <vector>
#include <queue>

#define SIZE 100000

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

struct Edge {
    Edge(int to, int w) : to(to), w(w) {}
    int to, w;
};

struct Node {
    Node() {}
    Node(int in, int w) : in(in), w(w) {}
    int in, w;
};

int T, N, M, a, b, c;
vector<Edge> edges[SIZE + 1];
Node nodes[SIZE + 1];
queue<int> q;

void init() {
    for(int i = 1; i <= SIZE; i++) {
        nodes[i] = Node(0, 0);
        while(!edges[i].empty()) edges[i].pop_back();
    }
    while(!q.empty()) q.pop();
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        init();
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= M; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edges[a].push_back(Edge(b, c));            
            nodes[b].in++;
        }
        q.push(1);
        while(!q.empty()) {
            int current = q.front(); q.pop();
            for(Edge e : edges[current]) {
                int next = e.to;
                nodes[next].w = max(nodes[next].w, nodes[current].w + e.w);
                nodes[next].in--;
                if(nodes[next].in == 0) q.push(next);
            }
        }
        printf("#%d %d\n", t, nodes[N].w);
    }
    return 0;
}