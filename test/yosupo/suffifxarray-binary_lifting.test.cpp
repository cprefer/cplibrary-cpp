#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
#include "string/suffix_array.hpp"

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  auto suffix_array = binary_lifting(s);
  for (int x : suffix_array) {
    cout << x << " ";
  }
}