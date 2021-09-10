#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;

    int l, r;
    for (int i = 0; i < t; i++) {
        cin >> l >> r;
        if (l <= (r / 2) + 1) {
            cout << (r - 1) / 2 << endl;
        } else {
            cout << r - l << endl;
        }
    }
    return 0;
}