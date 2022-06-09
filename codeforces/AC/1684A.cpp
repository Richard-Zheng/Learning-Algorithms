#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        if (n.size() > 2) {
            int ans = 10;
            for (int i = 0; i < n.size(); i++) {
                ans = min(ans, n[i] - '0');
            }
            cout << ans << endl;
        } else {
            cout << n[1] << endl;
        }
    }
}