#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<pair<int, int>> actions;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int min_pos = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[min_pos]) {
                    min_pos = j;
                }
            }
            if (min_pos > i) {
                actions.push_back({i, min_pos});
                int tmp = a[min_pos];
                for (int j = min_pos; j > i; j--) {
                    a[j] = a[j - 1];
                }
                a[i] = tmp;
            }
        }

        cout << actions.size() << '\n';
        for (auto &lr : actions) {
            cout << lr.first + 1 << ' ' << lr.second + 1 << ' ' << lr.second - lr.first << '\n';
        }
    }
    return 0;
}