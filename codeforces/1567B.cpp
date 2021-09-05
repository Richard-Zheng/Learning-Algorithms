#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;

    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        int axor = 0;
        for (int j = 1; j < a; j++) {
            axor ^= j;
        }
        int k = axor ^ b;
        if (axor == b) {
            cout << a << endl;
            continue;
        } else if (k == a) {
            cout << a + 2 << endl;
        } else {
            cout << a + 1 << endl;
        }
    }
    return 0;
}