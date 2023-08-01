#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> dt(vector<vector<int>> g) {
  int n = g.size();
  vector<bool> done(n);
  vector<int> size(n), hsize(n);
  vector<vector<pair<int, int>>> res(n);
  function<void(int)> divide = [&](int u) {
    vector<int> vs;
    function<void(int, int)> fsize = [&](int u, int p) {
      vs.push_back(u);
      size[u] = 1;
      hsize[u] = 0;
      for (int v : g[u]) {
        if (v != p and not done[v]) {
          fsize(v, u);
          size[u] += size[v];
          hsize[u] = max(hsize[u], size[v]);
        }
      }
    };
    fsize(u, -1);
    int root = u;
    for (int v : vs) {
      if (max(size[u] - size[v], hsize[v]) < max(size[u] - size[root], hsize[root])) {
        root = v;
      }
    }
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
      res[u].emplace_back(root, d);
      for (int v : g[u]) {
        if (v != p and not done[v]) {
          dfs(v, u, d + 1);
        }
      }
    };
    dfs(root, -1, 0);
    done[root] = true;
    for (int v : g[root]) {
      if (not done[v]) {
        divide(v);
      }
    }
  };
  divide(0);
  return res;
}