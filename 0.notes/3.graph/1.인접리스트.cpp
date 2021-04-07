/*
1 - 2 - 5
|   | /
3 - 4
*/

#include <stdio.h>
#include <vector>
#define N 5

using namespace std;

struct Edge {
    Edge() {}
    Edge(int to, int weight) : to(to), weight(weight) {}
    int to, weight;
};

vector<Edge> edges[N + 1];

int main() {
    edges[1].push_back(Edge(2, 1));
    edges[1].push_back(Edge(3, 2));
    edges[2].push_back(Edge(1, 3));
    edges[2].push_back(Edge(4, 4));
    edges[2].push_back(Edge(5, 5));
    edges[3].push_back(Edge(1, 6));
    edges[3].push_back(Edge(4, 7));
    edges[4].push_back(Edge(2, 8));
    edges[4].push_back(Edge(3, 9));
    edges[4].push_back(Edge(5, 10));
    edges[5].push_back(Edge(2, 11));
    edges[5].push_back(Edge(4, 12));

    for(int i = 1; i <= N; i++) {
        for(Edge e : edges[i]) {
            printf("%d -> %d (%d)\n", i, e.to, e.weight);
        }
    }

// 1 -> 2 (1)
// 1 -> 3 (2)
// 2 -> 1 (3)
// 2 -> 4 (4)
// 2 -> 5 (5)
// 3 -> 1 (6)
// 3 -> 4 (7)
// 4 -> 2 (8)
// 4 -> 3 (9)
// 4 -> 5 (10)
// 5 -> 2 (11)
// 5 -> 4 (12)

    return 0;
}