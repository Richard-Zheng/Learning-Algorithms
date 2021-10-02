#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;

    string s;
    int a, b, c;
    while (t--) {
        cin >> s;
        a = 0;
        b = 0;
        c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                a++;
            } else if (s[i] == 'B') {
                b++;
            } else if (s[i] == 'C') {
                c++;
            }
        }

        if (b == a + c) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}