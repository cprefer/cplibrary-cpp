#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#define ERROR 1e-10

#include <bits/stdc++.h>
using namespace std;

#include "geometry.hpp"

using f64 = double;
using point = Point<f64>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  point a, b;
  cin >> a >> b;
  int q;
  cin >> q;
  for (int qi = 0; qi < q; qi += 1) {
    point p;
    cin >> p;
    cout << p.projection(a, b) << "\n";
  }
}