#include <cstring>
#include <iostream>
using namespace std;
int main() {
    string a;
    cin >> a;
    if (a[a.length() - 2] != '0') {
        cout << a[a.length() - 2];
    }
    cout << a[a.length() - 1];
    cout << ' ';
    for (int i = 0; i < a.length() - 2; i++) {
        cout << a[i];
    }
}