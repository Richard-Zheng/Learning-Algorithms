#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    int n;
    string s;
    while (t--) {
        cin >> n >> s;

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != '0') {
                ans++;
            }
            ans += (s[i] - '0');
        }
        ans += s[n - 1] - '0';
        cout << ans << endl;
    }
}