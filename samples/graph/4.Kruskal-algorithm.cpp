#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 8

using namespace std;

struct Edge {
    Edge(int from, int to, int w): from(from), to(to), w(w) {}
    int from, to, w;
    bool operator<(const Edge&e) const {
        return w < e.w;
    }
};

vector<Edge> edges;
int parent[N + 1];
int sum = 0;

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
void _union(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}
void init() {
    for(int i = 1; i <= N; i++) parent[i] = i;
}

int kruskal() {
    sort(edges.begin(), edges.end()); // 내림차순 정렬

    int selected = 0;
    int sum = 0;

    for(Edge e : edges) {
        if(find(e.from) == find(e.to)) continue;
        _union(e.from, e.to);
        sum += e.w;
        selected++;
        printf("%d %d\n", e.from, e.to);
        if(selected == N) break;
    }
    return sum;

}

int main() {
    init();
    edges.push_back(Edge(1, 2, 6));
    edges.push_back(Edge(1, 3, 6));
    edges.push_back(Edge(2, 4, 7));
    edges.push_back(Edge(2, 5, 3));
    edges.push_back(Edge(3, 6, 4));
    edges.push_back(Edge(3, 7, 1));
    edges.push_back(Edge(4, 8, 8));
    edges.push_back(Edge(5, 8, 1));
    edges.push_back(Edge(6, 8, 2));
    edges.push_back(Edge(7, 8, 9));

    printf("%d", kruskal());

    return 0;
}