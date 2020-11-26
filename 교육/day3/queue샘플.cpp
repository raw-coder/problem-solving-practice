#include <stdio.h>
#include <queue>
#include <deque>

using namespace std;

queue<int> q;
deque<int> dq;

int main() {
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty()) {
        printf("%d\n", q.front());
        q.pop();
    }

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);

    while(!dq.empty()) {
        printf("%d\n", dq.front());
        dq.pop_front();
    }

    return 0;
}