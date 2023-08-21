#include <bits/stdc++.h>
using namespace std;
vector<int> lyndon(const string &s) {
  int n = s.size();
  vector<int> res;
  for (int i = 0, j, k; i < n;) {
    j = (k = i) + 1;
    for (j = (k = i) + 1; j < n and s[k] <= s[j]; j += 1) {
      k = s[k] < s[j] ? i : k + 1;
    }
    while (i <= k) {
      res.push_back(i += (j - k));
    }
  }
  return res;
}