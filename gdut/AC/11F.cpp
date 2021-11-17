#include <iostream>
#include <map>
using namespace std;
const int MAXM = 4e5;
int a[MAXM];
int main() {
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        a[i] %= m;
    }
    map<int, int> exist;
    exist[0] = 1;
    int ansi = -1;
    int ansj = -1;
    for (int i = 1; i <= m; i++) {
        if (exist.count(a[i])) {
            if (exist[a[i]] >= ansi) {
                ansi = exist[a[i]];
                ansj = i;
            }
        }
        exist[a[i]] = i + 1;
    }
    if (ansi != -1) {
        cout << ansi << ' ' << ansj << endl;
    } else {
        cout << -1 << endl;
    }
}