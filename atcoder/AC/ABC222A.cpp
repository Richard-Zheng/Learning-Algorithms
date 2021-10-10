#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s.length() < 4) {
        for (int i = 1; i <= (4 - s.length()); i++) {
            cout << '0';
        }
    }
    cout << s << endl;
    return 0;
}