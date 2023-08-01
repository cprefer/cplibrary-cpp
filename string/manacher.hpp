#include <bits/stdc++.h>
using namespace std;
vector<int> manacher(const string &s, char filler = 0) {
  string t(2 * s.size() + 1, filler);
  for (int i = 0; i < (int)s.size(); i += 1) {
    t[2 * i + 1] = s[i];
  }
  int n = t.size();
  vector<int> m(n);
  for (int i = 0, j = 0; i < n; i += 1) {
    if (j + m[j] > i) {
      m[i] = min(m[2 * j - i], j + m[j] - i);
    }
    while (i >= m[i] and i + m[i] < n and t[i - m[i]] == t[i + m[i]]) {
      m[i] += 1;
    }
    if (i + m[i] > j + m[j]) {
      j = i;
    }
  }
  for (int &mi : m) {
    mi -= 1;
  }
  return {next(m.begin()), prev(m.end())};
}