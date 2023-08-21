#include <bits/stdc++.h>
#include "modint.hpp"
using namespace std;

vector<int> butterfly(int n) {
  vector<int> r(n);
  for (int i = 1; i < n; i += 1) {
    r[i] = r[i / 2] / 2 | (i % 2 ? n / 2 : 0);
  }
  return r;
}
template <typename T, T mod, T g> void fft(vector<ModInt<T, mod, g>> &a, const vector<int> &r, bool inv = false) {
  using mint = ModInt<T, mod, g>;
  int n = a.size();
  for (int i = 0; i < n; i += 1) {
    if (i < r[i]) {
      swap(a[i], a[r[i]]);
    }
  }
  for (int m = 1; m < n; m *= 2) {
    auto _w = (inv ? mint(g).inv() : mint(g)).pow((mod - 1) / 2 / m);
    for (int i = 0; i < n; i += m * 2) {
      mint w(1);
      for (int j = 0; j < m; j += 1, w *= _w) {
        auto &x = a[i + j + m], &y = a[i + j], t = w * x;
        x = y - t;
        y += t;
      }
    }
  }
  if (inv) {
    auto inverse = mint(n).inv();
    for (auto &ai : a) {
      ai *= inverse;
    }
  }
}

template <typename T, T mod, T g>
vector<ModInt<T, mod, g>> convolution(vector<ModInt<T, mod, g>> a, vector<ModInt<T, mod, g>> b) {
  size_t m = a.size() + b.size() - 1;
  int n = bit_ceil(m);
  auto r = butterfly(n);
  a.resize(n);
  fft(a, r);
  b.resize(n);
  fft(b, r);
  for (int i = 0; i < n; i += 1) {
    a[i] *= b[i];
  }
  fft(a, r, true);
  a.resize(m);
  return a;
}

template <typename mint> struct RelaxedConvolution {
  int n;
  vector<mint> a, b, c;
  RelaxedConvolution() : n(0) {}
  mint get(const mint &ai, const mint &bi) {
    a.push_back(ai);
    b.push_back(bi);
    c.push_back(0);
    c.push_back(0);
    n += 1;
    if (n % 4) {
      if (n < 4) {
        for (int i = 0; i < n; i += 1) {
          c[n - 1] += a[i] * b[n - 1 - i];
        }
      } else {
        for (int i = 0; i < n % 4; i += 1) {
          c[n - 1] += a[i] * b[n - 1 - i] + a[n - 1 - i] * b[i];
        }
      }
    } else {
      int m = n & -n;
      if (m == n) {
        auto ab = convolution(a, b);
        for (int i = n - 1; i < 2 * n - 1; i += 1) {
          c[i] += ab[i];
        }
      } else {
        auto ab = convolution(vector<mint>{a.begin(), a.begin() + 2 * m - 1}, vector<mint>{b.end() - m, b.end()});
        auto ba = convolution(vector<mint>{b.begin(), b.begin() + 2 * m - 1}, vector<mint>{a.end() - m, a.end()});
        for (int i = n - 1; i < n + m - 1; i += 1) {
          c[i] += ab[i - (n - m)] + ba[i - (n - m)];
        }
      }
    }
    return c[n - 1];
  }
};