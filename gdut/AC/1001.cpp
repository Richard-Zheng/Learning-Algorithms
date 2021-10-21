#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s, k;
    while (t--) {
        cin >> s >> k;
        int ans = 0;
        int ss = s.length();
        int ks = k.length();
        for (int i = 0; i <= ss - ks; i++) {
            bool ok = true;
            for (int j = 0; j < ks; j++) {
                if (i + j > s.length() || s[i + j] != k[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}