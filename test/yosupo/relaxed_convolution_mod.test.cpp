#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#include "math/convolution.hpp"

using mint = ModInt<i64, 998244353, 3>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  vector<mint> a(n), b(m);
  for (auto &ai : a) {
    cin >> ai;
  }
  for (auto &bi : b) {
    cin >> bi;
  }
  RelaxedConvolution<mint> relaxed_convolution;
  a.resize(n + m - 1);
  b.resize(n + m - 1);
  for (int i = 0; i < n + m - 1; i += 1) {
    cout << relaxed_convolution.get(a[i], b[i]) << " ";
  }
}