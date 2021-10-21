#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    double a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        cout << fixed << setprecision(6) << a * 0.25 + b * 0.25 - c * 0.5 << '\n';
    }
}