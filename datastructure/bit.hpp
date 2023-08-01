#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <typename T = i64> struct BIT {
  int n;
  vector<T> inner;
  BIT() : n(1), inner(1) {}
  void resize(int new_n) {
    inner.resize(new_n);
    for (int i = 1; i <= new_n; i += 1) {
      if (i + (i & -i) > n and i + (i & -i) <= new_n) {
        inner[i + (i & -i) - 1] += inner[i - 1];
      }
    }
    n = new_n;
  }
  void add(int i, T x) {
    while (i >= n) {
      resize(2 * n);
    }
    for (i += 1; i <= n; i += i & -i) {
      inner[i - 1] += x;
    }
  }
  T sum(int i) {
    if (i < 0) {
      return 0;
    }
    T x = 0;
    for (i = min(i + 1, n); i; i -= i & -i) {
      x += inner[i - 1];
    }
    return x;
  }
};
