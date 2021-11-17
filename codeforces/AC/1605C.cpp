#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (s.find("aa") != s.npos) {
        cout << "2\n";
        return;
    } else if (s.find("aba") != s.npos) {
        cout << "3\n";
        return;
    } else if (s.find("aca") != s.npos) {
        cout << "3\n";
        return;
    } else if (s.find("abca") != s.npos || s.find("acba") != s.npos) {
        cout << "4\n";
        return;
    } else if (s.find("abbacca") != s.npos || s.find("accabba") != s.npos) {
        cout << "7\n";
        return;
    } else {
        cout << "-1\n";
        return;
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}