#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;

const int howManyEdges = 10;
class DSU {
public:
  vector<int> parent;
  vector<int> size;

  DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

  void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
  }

  int find_set(int v) {
    if (v == parent[v]) {
      return v;
    } else {
      return parent[v] = find_set(parent[v]);
    }
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (size[a] < size[b])
        swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
};

class Node {
public:
  int x;
  int y;
  int z;
};

class Edge {
public:
  ll d;
  int n1;
  int n2;
};

int main() {
  int a, b, c;
  vector<Node> nodes;
  while (scanf("%d,%d,%d", &a, &b, &c) != EOF) {
    Node n;
    n.x = a;
    n.y = b;
    n.z = c;
    nodes.push_back(n);
  }

  vector<Edge> edges;
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = i + 1; j < nodes.size(); j++) {
      Edge e;
      e.n1 = i;
      e.n2 = j;
      ll dx = nodes[i].x - nodes[j].x;
      ll dy = nodes[i].y - nodes[j].y;
      ll dz = nodes[i].z - nodes[j].z;
      e.d = dx * dx * 1LL + dy * dy * 1LL + dz * dz * 1LL;
      edges.push_back(e);
    }
  }

  sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.d < b.d; });

  DSU dsu(nodes.size());

  int connections = 0;
  for (int i = 0; i < edges.size(); i++) {
    Edge e = edges[i];
    if (dsu.find_set(e.n1) != dsu.find_set(e.n2)) {
      connections++;
      dsu.union_sets(e.n1, e.n2);
    }
    if (connections == nodes.size() - 1) {
      printf("Output is p2 %lld\n", 1LL * nodes[e.n1].x * nodes[e.n2].x);
      break;
    }
    if (i == howManyEdges) {
      vector<int> sizes;
      for (int i = 0; i < nodes.size(); i++) {
        if (dsu.find_set(i) == i)
          sizes.push_back(dsu.size[i]);
      }

      sort(sizes.begin(), sizes.end(), greater<>());

      ll p1 = 1LL * sizes[0] * sizes[1] * sizes[2];
      printf("Output is p1 %lld\n", p1);
    }
  }
}
