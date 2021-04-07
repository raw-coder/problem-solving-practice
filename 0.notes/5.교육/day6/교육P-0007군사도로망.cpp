// 이미 연결된 간선 가중치 -1 곱해서 MST 구하기
// 결과 = MST 간선의 가중치 합 + 기존 연결된 간선의 가중치 합

#include <stdio.h>
#include <vector>
#include <algorithm>
#define SIZE 100000

using namespace std;

int T, N, M, K, a, b, c;

struct Edge {
    Edge(int from, int to, int w): from(from), to(to), w(w) {}
    int from, to, w;
    bool operator<(const Edge&e) const {
        return w < e.w;
    }
};
vector<Edge> edges;
int parent[SIZE + 1];

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
    edges.clear();
    for(int i = 1; i <= SIZE; i++) parent[i] = i;
}

long long kruskal() {
    sort(edges.begin(), edges.end());

    int selected = 0;
    long long sum = 0;

    for(Edge e : edges) {
        if(find(e.from) == find(e.to)) continue;
        _union(e.from, e.to);
        sum += e.w;        
        if(selected == N) break;
    }
    return sum;
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        init();
        scanf("%d %d %d", &N, &M, &K);

        long long sum = 0;
        for(int i = 1; i <= M; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back(Edge(a, b, c * -1));
            sum += c;
        }
        for(int i = 1; i <= K; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back(Edge(a, b, c));
        }
        printf("#%d %lld\n", t, sum + kruskal());
    }
    return 0;
}
