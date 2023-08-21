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
    for (int i = 1; i < (n + 2) and (n + 2) % i == 0; i *= 2) {
      c.resize(max((int)c.size(), n + i * 2 - 1));
      if (i * 2 == (n + 2)) {
        auto ab = convolution(vector<mint>{a.end() - i, a.end()}, vector<mint>{b.end() - i, b.end()});
        for (int j = 0; j < i * 2 - 1; j += 1) {
          c[n + j] += ab[j];
        }
      } else {
        auto ab =
            convolution(vector<mint>{a.end() - i, a.end()}, vector<mint>{b.begin() + i - 1, b.begin() + 2 * i - 1});
        auto ba =
            convolution(vector<mint>{b.end() - i, b.end()}, vector<mint>{a.begin() + i - 1, a.begin() + 2 * i - 1});
        for (int j = 0; j < i * 2 - 1; j += 1) {
          c[n + j] += ab[j] + ba[j];
        }
      }
    }
    return c[n++];
  }
};