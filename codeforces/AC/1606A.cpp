#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s[s.length() - 1] == s[0]) {
            cout << s << '\n';
            continue;
        }
        s[s.length() - 1] = (!(s[s.length() - 1] - 'a')) + 'a';
        cout << s << endl;
    }
}