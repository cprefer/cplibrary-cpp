#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <bits/stdc++.h>
using namespace std;

#include "graph/tcc.hpp"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i += 1) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto tc = tcc(g);
  cout << tc.size() << "\n";
  for (auto &tci : tc) {
    cout << tci.size() << " ";
    for (int x : tci) {
      cout << x << " ";
    }
    cout << "\n";
  }
}