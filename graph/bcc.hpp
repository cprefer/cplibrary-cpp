#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bcc(const vector<vector<int>> &g) {
  int n = g.size();
  vector<int> pos(n, -1), stack;
  vector<vector<int>> res;
  function<int(int, int)> dfs = [&](int u, int p) {
    int low = pos[u] = stack.size(), son = 0;
    stack.push_back(u);
    for (int v : g[u]) {
      if (v != p) {
        if (~pos[v]) {
          low = min(low, pos[v]);
        } else {
          int end = stack.size(), low_v = dfs(v, u);
          low = min(low, low_v);
          if (low_v >= pos[u] and (~p or son++)) {
            res.emplace_back(stack.begin() + end, stack.end());
            res.back().push_back(u);
            stack.resize(end);
          }
        }
      }
    }
    return low;
  };
  for (int i = 0; i < n; i += 1) {
    if (pos[i] == -1) {
      dfs(i, -1);
      res.emplace_back(move(stack));
    }
  }
  return res;
}