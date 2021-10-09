#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    long long n;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << '0';
        } else {
            cout << '-' << n - 1;
        }
        cout << ' ' << n << endl;
    }
    return 0;
}