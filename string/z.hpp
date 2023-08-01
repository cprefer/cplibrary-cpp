#include <bits/stdc++.h>
using namespace std;
vector<int> z(const string &s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, j = 0; i < n; i += 1) {
    z[i] = min(z[i - j], max(j + z[j] - i, 0));
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
      z[i] += 1;
    }
    if (i + z[i] > j + z[j]) {
      j = i;
    }
  }
  z[0] = n;
  return z;
}