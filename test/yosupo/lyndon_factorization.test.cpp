#define PROBLEM "https://judge.yosupo.jp/problem/lyndon_factorization"

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#include "string/lyndon.hpp"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  auto a = lyndon(s);
  cout << "0 ";
  for (int ai : a) {
    cout << ai << " ";
  }
}