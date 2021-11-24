#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n % 2 == 0) {
            if (n % 4 == 0) {
                int t = n / 4;
                t = sqrt(t);
                if (t * t == n / 4) {
                    cout << "YES\n";
                    continue;
                }
            }
            int t = n / 2;
            t = sqrt(t);
            if (t * t == n / 2) {
                cout << "YES\n";
                continue;
            } else {
                cout << "NO\n";
                continue;
            }
        } else {
            cout << "NO\n";
            continue;
        }
    }
}