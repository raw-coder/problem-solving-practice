### sort, compare, operator overloading

compare 함수를 구현하여 sort 기준을 customizing 할 수 있다.

```cpp
#include <stdio.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};

    sort(arr, arr + 5);

    for(int i = 0; i < 5; i++) printf("%d ", arr[i]); // 1 2 3 4 5

    sort(arr, arr + 5, compare);

    for(int i = 0; i < 5; i++) printf("%d\n", arr[i]); // 5 4 3 2 1
}

```

struct operation overloading을 통해 sort 기준을 customizing 할 수 있다.

```cpp
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    Node(int from, int to, int cost):from(from), to(to), cost(cost) {}
    int from, to, cost;

    bool operator<(const Node&a) {
        return a.cost < cost;
    }
};

vector<Node> nodes;

int main() {
    nodes.push_back(Node(1, 2, 5));
    nodes.push_back(Node(2, 3, 3));
    nodes.push_back(Node(3, 4, 2));
    nodes.push_back(Node(4, 5, 4));
    nodes.push_back(Node(5, 6, 1));

    sort(nodes.begin(), nodes.end());

    for(int i = 0; i < 5; i++) printf("%d %d %d\n", nodes[i].from, nodes[i].to, nodes[i].cost);
    // 1 2 5
    // 4 5 4
    // 2 3 3
    // 3 4 2
    // 5 6 1
}

```