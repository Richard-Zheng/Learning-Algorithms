#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        int mini = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < s[mini]) {
                mini = i;
            }
        }
        cout << s[mini] << ' ';
        for (int i = 0; i < s.length(); i++) {
            if (i != mini) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}