#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> scc(const vector<vector<int>> &g) {
  int n = g.size();
  vector<bool> done(n);
  vector<int> pos(n, -1), stack;
  vector<vector<int>> res;
  function<int(int)> dfs = [&](int u) {
    int low = pos[u] = stack.size();
    stack.push_back(u);
    for (int v : g[u]) {
      if (not done[v]) {
        low = min(low, ~pos[v] ? pos[v] : dfs(v));
      }
    }
    if (low == pos[u]) {
      res.emplace_back(stack.begin() + low, stack.end());
      for (int v : res.back()) {
        done[v] = true;
      }
      stack.resize(low);
    }
    return low;
  };
  for (int i = 0; i < n; i += 1) {
    if (not done[i]) {
      dfs(i);
    }
  }
  ranges::reverse(res);
  return res;
}