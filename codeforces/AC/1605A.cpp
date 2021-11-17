#include <cmath>
#include <iostream>
using namespace std;
void solve() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << ((abs(a1 + a3 - 2 * a2) % 3) ? 1 : 0) << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}