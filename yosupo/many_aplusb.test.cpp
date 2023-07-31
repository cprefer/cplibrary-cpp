#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    i64 a, b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
}