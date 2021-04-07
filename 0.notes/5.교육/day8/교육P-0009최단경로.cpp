#include <stdio.h>
#include <vector>
#include <queue>
#define SIZE 100000

using namespace std;

int T, N, M, a, b, c;

struct Node {
    Node() {}
    Node(int no, int d): no(no), d(d) {}
    int no, d;
    bool operator<(const Node&n) const {
        return d > n.d;
    }
};
struct Edge {
    Edge(int to, int c): to(to), c(c) {}
    int to, c;
};

vector<Edge> edges[SIZE + 1];
Node nodes[SIZE + 1];
priority_queue<Node> pq;

void dijkstra() {
    nodes[1].d = 0;
    pq.push(nodes[1]);

    while(!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if(current.no == N) break;

        for(Edge e : edges[current.no]) {            
            if(nodes[e.to].d > current.d + e.c) {
                nodes[e.to].d = current.d + e.c;
                pq.push(nodes[e.to]);
            }
        }        
    }
}

void init() {
    for(int i = 1; i <= N; i++) {
        nodes[i] = Node(i, __INT_MAX__);
        while(!edges[i].empty()) edges[i].pop_back();
    }
    while(!pq.empty()) pq.pop();
}

int main() {    
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        init();
        for(int i = 1; i <= M; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edges[a].push_back(Edge(b, c));
            edges[b].push_back(Edge(a, c));
        }
        dijkstra();
        printf("#%d %d\n", t, nodes[N].d < __INT_MAX__ ? nodes[N].d : -1);
    }
    return 0;
}
