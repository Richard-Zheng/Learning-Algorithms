#include <iostream>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;
const int MAXN = 10e5;
int main() {
    int t;
    cin >> t;

    int n;
    map<int, int> p;
    while (t--) {
        cin >> n;

        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            p[tmp] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            p[tmp] = i;
        }

        int l = p[2 * n];
        int ans = numeric_limits<int>::max();
        for (int i = 2 * n; i >= 1; i--) {
            if (i % 2 == 0) { // i is even
                l = min(l, p[i]);
            } else {
                ans = min(ans, p[i] + l);
            }
        }
        cout << ans << endl;
    }
    return 0;
}