#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include <bits/stdc++.h>
using namespace std;

#include "graph/bcc.hpp"

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
  auto bc = bcc(g);
  cout << bc.size() << "\n";
  for (auto &bci : bc) {
    cout << bci.size() << " ";
    for (int x : bci) {
      cout << x << " ";
    }
    cout << "\n";
  }
}