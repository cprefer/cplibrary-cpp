#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <bits/stdc++.h>
#include "string/suffix_array.hpp"

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  auto ans = s.size() * (s.size() + 1) / 2;
  auto lcp = binary_lifting(s).second;
  for (int x : lcp) {
    ans -= x;
  }
  cout << ans;
}