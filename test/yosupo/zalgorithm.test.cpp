#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
#include "string/z.hpp"

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  auto z = get_z(s);
  z[0] = s.size();
  for (int zi : z) {
    cout << zi << " ";
  }
}