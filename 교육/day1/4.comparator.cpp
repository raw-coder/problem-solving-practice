#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node {
  int from, to, cost;
  bool operator<(const Node&a) {
    return a.cost > cost;
  }
};

bool compare(Node a, Node b) {
  return a.cost > b.cost;
}

int main() {
  int arr[] = {5, 3, 2, 4, 1};
  sort(arr, arr + 5);
  for(int i = 0; i < 5; i++) {
    printf("%d\n", arr[i]);
  }

  Node arrN[5];
  for(int i = 0; i < 5; i++) {
    arrN[i].from = i + 1;
    arrN[i].to = i + 2;
    arrN[i].cost = i * 2 + 1;
  }
  sort(arrN, arrN + 5, compare);
  for(int i = 0; i < 5; i++) {
    printf("%d %d %d\n", arrN[i].from, arrN[i].to, arrN[i].cost);
  }
  sort(arrN, arrN + 5);
  for(int i = 0; i < 5; i++) {
    printf("%d %d %d\n", arrN[i].from, arrN[i].to, arrN[i].cost);
  }
}