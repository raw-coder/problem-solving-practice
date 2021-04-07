#include <stdio.h>
#include <queue>
#include <vector>
#define SIZE 50000

using namespace std;

int T, N, M, X, s, e, t;

struct Node {
    Node(int n, int d): n(n), d(d) {}
    int n, d;
    bool operator<(const Node&n) const {
        return d > n.d;
    }
};

struct Edge {
    Edge(int to, int t): to(to), t(t) {}
    int to, t;
};

priority_queue<Node> pq;
vector<Edge> edges[SIZE + 1], edges2[SIZE + 1];
int d[SIZE + 1], d2[SIZE + 1];

void dijkstra() {
    pq.push(Node(X, 0));    
    d[X] = 0;
    while(!pq.empty()) {
        Node current = pq.top(); pq.pop();        
        for(Edge e : edges[current.n]) {
            if(d[e.to] > d[current.n] + e.t) {
                d[e.to] = d[current.n] + e.t;
                pq.push(Node(e.to, d[e.to]));
            }
        }
    }
    pq.push(Node(X, 0));
    d2[X] = 0;
    while(!pq.empty()) {
        Node current = pq.top(); pq.pop();        
        for(Edge e : edges2[current.n]) {
            if(d2[e.to] > d2[current.n] + e.t) {
                d2[e.to] = d2[current.n] + e.t;
                pq.push(Node(e.to, d2[e.to]));
            }
        }
    }
}

void init() {
    while(!pq.empty()) pq.pop();
    for(int i = 1; i <= N; i++) {
        d[i] = d2[i] = __INT_MAX__;
        while(!edges[i].empty()) edges[i].pop_back();
        while(!edges2[i].empty()) edges2[i].pop_back();
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &N, &M, &X);
        init();
        for(int i = 1; i <= M; i++) {
            scanf("%d %d %d", &s, &e, &t);
            edges[s].push_back(Edge(e, t));
            edges2[e].push_back(Edge(s, t));
        }
        dijkstra();

        int sum = -1;
        for(int i = 1; i <= N; i++) {
            sum = max(sum, d[i] + d2[i]);
        }
        printf("#%d %d\n", tc, sum);
    }
    return 0;
}