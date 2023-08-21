#include <bits/stdc++.h>
using namespace std;
template <typename T, T mod, T g = 0> struct ModInt {
  using mint = ModInt<T, mod, g>;
  T x;
  ModInt(T _x = 0) : x(_x) {
    if (x < 0 or x >= mod) {
      x %= mod;
      if (x < 0) {
        x += mod;
      }
    }
  }

  ModInt(const mint &x) : x(x.x) {}
  ModInt &operator=(const mint &_x) {
    x = _x.x;
    return *this;
  }

  mint pow(T r) const {
    mint res(1), a = *this;
    for (; r; r >>= 1, a *= a) {
      if (r & 1) {
        res *= a;
      }
    }
    return res;
  }

  mint inv() const { return pow(mod - 2); }

  mint &operator+=(const mint &rhs) {
    if ((x += rhs.x) >= mod) {
      x -= mod;
    }
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    if ((x -= rhs.x) < 0) {
      x += mod;
    }
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    (x *= rhs.x) %= mod;
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
  mint operator+(const mint &rhs) const { return mint(*this) += rhs; }
  mint operator-(const mint &rhs) const { return mint(*this) -= rhs; }
  mint operator*(const mint &rhs) const { return mint(*this) *= rhs; }
  mint operator/(const mint &rhs) const { return mint(*this) /= rhs; }
  friend istream &operator>>(istream &is, mint &rhs) {
    T x;
    is >> x;
    rhs = mint(x);
    return is;
  }
  friend ostream &operator<<(ostream &os, const mint &rhs) { return os << rhs.x; }
};