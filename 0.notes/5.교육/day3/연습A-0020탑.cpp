#include <stdio.h>
#include <stack>

using namespace std;

struct Node {
    Node(int index, int value):index(index), value(value) {}
    int index, value;
};

stack<Node> s;

int T, N, x;

void init() {
    while(!s.empty()) {
        s.pop();
    }
}

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        int ans = 0;
        init();
        for(int i = 1; i <= N; i++) {
            scanf("%d", &x);
            
            while(!s.empty() && s.top().value < x) {
                s.pop();
            }

            if(!s.empty()) {
                ans = (ans + s.top().index) % 1000000007;
            }            
            s.push(Node(i, x));
        }
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}