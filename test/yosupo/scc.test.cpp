#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
using namespace std;

#include "graph/scc.hpp"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i += 1) {
    cin >> u >> v;
    g[u].push_back(v);
  }
  auto sc = scc(g);
  cout << sc.size() << "\n";
  for (auto &sci : sc) {
    cout << sci.size() << " ";
    for (int x : sci) {
      cout << x << " ";
    }
    cout << "\n";
  }
}