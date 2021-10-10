#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
int main() {
    int t;
    cin >> t;

    int n;
    int c[MAXN][6];
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                cin >> c[i][j];
            }
        }

        bool find = false;
        for (int i = 1; i <= 5; i++) {
            for (int j = i + 1; j <= 5; j++) {
                bool ok = true;
                int counti = 0;
                int countj = 0;
                for (int s = 1; s <= n; s++) {
                    if (c[s][i] | c[s][j]) {
                        counti += c[s][i];
                        countj += c[s][j];
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok && counti >= n/2 && countj >= n/2) {
                    cout << "YES" << endl;
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        if (!find) {
            cout << "NO" << endl;
        }
    }
    return 0;
}