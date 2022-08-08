#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXS = 2e5 + 1;
int pre[MAXS];
int dp[MAXS][3];
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + (s[i] - '0');
  }
  int ans = n - pre[n];
  for (int i = 0; i <= n; i++) {
    if (pre[n] + i < n) {
      ans = min(ans, pre[i] - pre[pre[n] + i + 1] + pre[n] + i + 1 - i);
    }
    int j = min(pre[n] + i, n);
    ans = min(ans, pre[i] - pre[j] + pre[n]);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}