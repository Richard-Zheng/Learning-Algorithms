#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10e5;
int main() {
    int t;
    cin >> t;

    int n, x;
    vector<int> a;
    while (t--) {
        a.clear();
        cin >> n >> x;
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        if (n == x) {
            cout << "NO" << endl;
            continue;
        }
        if (is_sorted(a.begin(), a.end())) {
            cout << "YES" << endl;
            continue;
        }
        if (x <= n - 2) {
            cout << "YES" << endl;
            continue;
        }
        if (n == 3) {
            cout << "YES" << endl;
        }
        cout << "NO" << endl;
    }
    return 0;
}