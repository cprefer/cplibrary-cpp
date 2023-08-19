#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <bits/stdc++.h>
#include "string/manacher.hpp"

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  string t = "#";
  for (char c : s) {
    t += c;
    t += '#';
  }
  auto p = manacher(t);
  for (int i = 1; i + 1 < ssize(p); i += 1) {
    cout << p[i] - 1 << " ";
  }
}