#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
int a[MAXN];
int tmp[MAXN];
int main() {
    int t;
    cin >> t;

    int n, x;
    while (t--) {
        cin >> n >> x;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n >= 2 * x) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            tmp[i] = a[i];
        }
        sort(tmp + 1, tmp + n + 1);
        bool ok = true;
        for (int i = n - x + 1; i <= x; i++) {
            if (a[i] != tmp[i]) {
                cout << "NO" << endl;
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        }
    }
    return 0;
}