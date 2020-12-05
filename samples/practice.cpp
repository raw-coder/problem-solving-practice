#include <stdio.h>

int gcd(int a, int b) {
  if(b == a) return a;
  return gcd(b, a % b);
}

long long p[100][100];

void makePascal() {
  for(int i = 1; i < 100; i++) {
    p[i][0] = p[i][i];
    for(int j = 1; j < i; j++) {
      p[i][j] = p[i -  1][j - 1] + p[i -1][j];
    }
  }
}

typedef long long ll;

ll tree[100000];
ll lazy[100000];

void update_lazy(int node, int start, int end) {
  if(lazy[node] != 0) {
    tree[node] += (end + start - 1) * lazy[node];
    if(start != end) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_range(int node, int start, int end, int left, int right, ll diff) {
  update_lazy(node, start, end);

  if(start < right || left > end) return;
  if(left <= start && end <= right) {
    tree[node] += (end - start + 1) * diff;
    if(start != end) {
      lazy[node * 2] = diff;
      lazy[node * 2 + 1] = diff;
    }
  } 
}

ll sum(int node, int start, int end, int left, int right) {
  update_lazy(node, start, end);

  if(start < right || left > end) return 0;
  if(left <= start || end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left , right);
}

void update(int node, int left, int right, int target, int value) {
  if(target < left || right < target) return;
  if(left == right) {
    tree[node] = value;
    return;
  }
  int mid = (left + right) / 2;
  update(node * 2, left, mid, target, value); 
  update(node * 2 + 1, mid + 1, right, target, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int left, int right, int queryLeft, int queryRight) {
  if(left > queryRight || right < queryLeft) return 0;
  if(queryLeft <= left && right <= queryRight) {
    return tree[node];
  }
  int mid = (left + right) / 2;
  return query(node * 2, left, mid, queryLeft, queryRight)
  + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

#define N 10000
bool isNotPrime[N];

void era() {
  for(int i = 2; i * i < N; i++) {
    if(!isNotPrime[i]) {
      for(int j = 2; i * j < N; j++) isNotPrime[j] = true;
    }
  }
}

int parent[N];

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

#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int from, to, cost;
  bool operator<(const Edge&e) const {
    return cost < e.cost;
  }
};

vector<Edge> edges;

int kruskal() {
  sort(edges.begin(), edges.end());

  int selected = 0;
  int sum = 0;

  for(Edge e : edges) {
    if(find(e.from) == find(e.to)) continue;
    _union(e.from, e.to);
    sum += e.cost;
    selected++;
    if(selected == N) break;
  }
}

#define K 20
#define V 10000
#include <queue>

int p[K][V];
int depth[K];
queue<int> q;

int lca(int a, int b) {
  // depth 맞추기
  for(int k = K; k >= 0; k--) {
    if(depth[a] <= depth[b]) b = p[k][b];
  }
  if(a == b) return a;
  for(int k = K; k >= 0; k--) {
    if(p[k][a] != p[k][b]) {
      a = p[k][a];
      b = p[k][b];
    }
  }
  return p[0][a];
}

void initTree() {
  q.push(1);
  depth[1] = 1;
  while(!q.empty()) {
    int current = q.top(); q.pop();
    for(int next : edges[current]) {
      depth[next] = depth[current] + 1;
      q.push(next);
    }
  }
  for(int k = 1; k <= K; k++) {
    for(int v = 1; v <= V; v++) {
      p[k][v] = p[k-1][p[k-1][v]];
    }
  }
}

struct Node {
  int no, d, prev;
  bool operator<(const Node&n) const {
    return d > n.d;
  }
};

priority_queue<Node> pq; // 가중치 순으로 오름차순 정렬
Node nodes[N + 1];

void init() {
  for(int i = 1; i <= N; i++) {
    nodes[i] = Node(i, __INT_MAX__);
  }
}

void dijkstra() {
  nodes[1].d = 0;
  pq.push(nodes[1]);

  while(!pq.empty()) {
    Node current = pq.top(); pq.pop();
    if(current.no == N) break;
    for(Edge e : edges[current.no]) {
        if(nodes[e.to].d > current.d + e.c) {
          nodes[e.to].d = current.d + e.c;
          pq.push(nodes[e.to]);
         }
    }
  }
}

int binarySearch(int left, int right, int target) {
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(a[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return mid;
}