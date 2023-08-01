#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#include "datastructure/bit.hpp"
#include "datastructure/dt.hpp"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<i64> a(n);
  for (i64 &ai : a) {
    cin >> ai;
  }
  vector<vector<int>> g(n);
  for (int i = 1, u, v; i < n; i += 1) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto pars = dt(g);
  vector<BIT<i64>> bit(n), f_bit(n);
  auto modify = [&](int u, i64 x) {
    for (auto [p, d] : pars[u]) {
      bit[p].add(d, x);
    }
    for (int i = 0; i + 1 < ssize(pars[u]); i += 1) {
      f_bit[pars[u][i + 1].first].add(pars[u][i].second, x);
    }
  };
  auto query = [&](int u, int r) {
    i64 ans = 0;
    for (int i = 0; i < ssize(pars[u]); i += 1) {
      ans += bit[pars[u][i].first].sum(r - pars[u][i].second);
      if (i + 1 < ssize(pars[u])) {
        ans -= f_bit[pars[u][i + 1].first].sum(r - pars[u][i].second);
      }
    }
    return ans;
  };
  for (int i = 0; i < n; i += 1) {
    modify(i, a[i]);
  }
  for (int i = 0, op, p; i < q; i += 1) {
    cin >> op >> p;
    if (op == 0) {
      int x;
      cin >> x;
      modify(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(p, r - 1) - query(p, l - 1) << "\n";
    }
  }
}