#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    long long a, b, c, m;
    while (t--) {
        cin >> a >> b >> c >> m;
        if (a > c) {
            swap(a, c);
        }
        if (b > c) {
            swap(b, c);
        }
        long long max = a - 1 + b - 1 + c - 1;
        long long min = c - (a + b + 1);
        if ((min <= m) && (m <= max)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}