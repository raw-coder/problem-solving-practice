/*
1 -> 2 -> 5
| \  | /
V   VV
3 -> 4
*/

#include <stdio.h>
#include <queue>
#include <vector>
#define N 5

using namespace std;

int inDegrees[N + 1] = {0, };

vector<int> edges[N + 1];
queue<int> q; // node having zero in degree
vector<int> result;

int main() {
    edges[1].push_back(2); inDegrees[2]++;
    edges[1].push_back(3); inDegrees[3]++;
    edges[1].push_back(4); inDegrees[4]++;    
    edges[2].push_back(5); inDegrees[5]++;
    edges[3].push_back(4); inDegrees[4]++;
    edges[4].push_back(2); inDegrees[2]++;
    edges[4].push_back(5); inDegrees[5]++;

    for(int i = 1; i <= N; i++) {
        if(inDegrees[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int current = q.front(); 
        q.pop();
        result.push_back(current);

        for(int to : edges[current]) {
            inDegrees[to]--;
            if(inDegrees[to] == 0) q.push(to);
        }
    }

    for(int node : result) {
        printf("% d", node); // 1 3 4 2 5
    }

    return 0;
}