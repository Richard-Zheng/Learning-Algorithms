#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    string in;
    while(t--) {
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (s1[i] == '1' && s2[i] == '1') {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }
    }
    return 0;
}