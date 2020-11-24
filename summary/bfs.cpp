#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> edges[5];

int main() {
  edges[0].push_back(1);
  edges[0].push_back(2);
  edges[1].push_back(3);
  edges[1].push_back(4);
  edges[2].push_back(3);
  edges[2].push_back(4);
  edges[3].push_back(5);

  return 0;
}