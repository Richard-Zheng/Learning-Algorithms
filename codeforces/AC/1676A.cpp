#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int fs = s[0] + s[1] + s[2] - '0' - '0' - '0';
        int ls = s[3] + s[4] + s[5] - '0' - '0' - '0';
        if (fs == ls) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}