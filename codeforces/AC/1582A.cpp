#include <algorithm>
#include <iostream>
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + c) % 2 << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}