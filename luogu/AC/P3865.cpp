#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 1;
const int K = 27;
int st[MAXN][K + 1];
int lg[MAXN + 1];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int main() {
  lg[1] = 0;
  for (int i = 2; i <= MAXN; i++) {
    lg[i] = lg[i / 2] + 1;
  }
  int n, m;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    st[i][0] = read();
  }
  for (int j = 1; j <= K; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  while (m--) {
    int l, r;
    l = read();
    r = read();
    int j = lg[r - l + 1];
    cout << max(st[l][j], st[r - (1 << j) + 1][j]) << '\n';
  }
}