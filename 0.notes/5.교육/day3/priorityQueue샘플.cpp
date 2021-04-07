#include <stdio.h>
#include <queue>

using namespace std;

struct Node {
    Node(int a, int b, int c):a(a), b(b), c(c) {}
    int a, b, c;
    bool operator<(const Node&x) const {
        return a > x.a;
    }
};

priority_queue<int> pq;
priority_queue<Node> npq;

int main() {
    // pq == max heap
    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(1);
    pq.push(5);

    while (!pq.empty()) {
        printf("%d\n", pq.top());
        pq.pop();
    }

    npq.push(Node(1, 2, 3));
    npq.push(Node(3, 2, 3));
    npq.push(Node(5, 2, 3));
    npq.push(Node(2, 2, 3));
    npq.push(Node(5, 2, 3));

    while (!npq.empty()) {
        printf("%d %d %d\n", npq.top().a, npq.top().b, npq.top().c);
        npq.pop();
    }
    
    
}