#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 51;
int n;
string expect;
char ans[MAXN][MAXN];
void solve() {
    vector<int> one;
    vector<int> two;
    cin >> n >> expect;
    memset(ans, '?', sizeof(ans));
    for (int i = 1; i <= n; i++) {
        ans[i][i] = 'X';
    }
    for (int i = 1; i <= n; i++) {
        int expi = expect[i - 1] - '0';
        if (expi == 1) {
            for (vector<int>::iterator it = one.begin(); it != one.end(); it++) {
                ans[(*it)][i] = '=';
                ans[i][(*it)] = '=';
            }
            one.push_back(i);
        } else {
            two.push_back(i);
        }
    }
    for (vector<int>::iterator it = one.begin(); it != one.end(); it++) {
        for (int i = 1; i <= n; i++) {
            if (ans[(*it)][i] != '=' && (*it) != i) {
                ans[(*it)][i] = '+';
                ans[i][(*it)] = '-';
            }
        }
    }
    if (two.size() != 0 && two.size() <= 2) {
        cout << "NO\n";
        return;
    }
    if (two.size() != 0) {
        for (int i = 0; i < two.size() - 1; i++) {
            ans[two[i]][two[i + 1]] = '+';
        }
        ans[two[two.size() - 1]][two[0]] = '+';
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == '?') {
                switch (ans[j][i]) {
                    case '+':
                        ans[i][j] = '-';
                        break;
                    case '-':
                        ans[i][j] = '+';
                        break;
                    case '?':
                        ans[i][j] = '+';
                        ans[j][i] = '-';
                    default:
                        break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}