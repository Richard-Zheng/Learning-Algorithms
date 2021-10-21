#include <algorithm>
#include <iostream>
using namespace std;
const int MAXNM = 20 * 20;
int main() {
    int t;
    cin >> t;
    int n, m;
    int a[MAXNM];
    while (t--) {
        cin >> n >> m;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[cnt++];
            }
        }
        sort(a, a + cnt);
        int cou = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[cou++];
                if (j != m - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }
}