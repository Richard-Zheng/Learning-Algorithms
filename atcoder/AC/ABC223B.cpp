#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
string shift(int i) {
    string tmp = s.substr(i, s.length() - i);
    return tmp + s.substr(0, i);
}
int main() {
    cin >> s;

    string mi = s;
    string ma = s;
    for (int i = 0; i < s.length(); i++) {
        string tmp = shift(i);
        mi = min(mi, tmp);
        ma = max(ma, tmp);
    }
    cout << mi << endl
         << ma << endl;
}