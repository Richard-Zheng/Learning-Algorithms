#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;

    int n;
    string s;
    while (t--) {
        cin >> n >> s;
        if (n == 1) {
            cout << "-1 -1" << endl;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                cout << i << " " << i + 1 << endl;
                break;
            }

            if (i == n - 1) {
                cout << "-1 -1" << endl;
            }
        }
    }
    return 0;
}