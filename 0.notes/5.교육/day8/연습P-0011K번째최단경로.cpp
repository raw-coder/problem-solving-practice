// FIXME
#include <stdio.h>
#include <vector>
#include <queue>
#define SIZE 100000

using namespace std;

int T, N, M, K, x, y, z;

struct Node {
    Node() {}
    Node(int n, int d) : n(n), d(d) {};
    int n, d;    
    bool operator<(const Node&n) const {
        return d > n.d;
    }
};

struct Edge {
    Edge(int to, int d): to(to), d(d) {}
    int to, d;
};

priority_queue<Node> pq;
vector<Edge> edges[SIZE + 1];
Node nodes[SIZE + 1];
int visited[SIZE + 1];

void dijkstra() {
    while(!pq.empty()) {
        Node current = pq.top(); pq.pop();
        visited[current.n]++;

        if(visited[current.n] >= K) continue;
        if(current.n == N && visited[current.n] == K) break;
        
        for(Edge e : edges[current.n]) {
            if(visited[e.to] < K) {
                nodes[e.to].d = current.d + e.d;
                pq.push(Node(e.to, current.d + e.d));    
            }
        }
    }
}

void init() {
    for(int i = 1; i <= N; i++) {
        while(!edges[i].empty()) edges[i].pop_back();
        nodes[i] = Node(i, 0);
        visited[i] = 0;
    }
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d %d", &N, &M, &K);
        init();
        for(int i = 1; i <= M; i++) {
            scanf("%d %d %d", &x, &y, &z);
            edges[x].push_back(Edge(y, z));
            edges[y].push_back(Edge(x, z));
        }
        
        pq.push(nodes[1]);
        dijkstra();
        printf("#%d %d\n", t, visited[N] < K ? -1 : nodes[N].d);
    }
    return 0;
}