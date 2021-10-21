#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    double a1, b1, a2, b2;
    while (t--) {
        cin >> a1 >> b1 >> a2 >> b2;
        double a = a1 / b1;
        double b = a2 / b2;
        if (a >= b) {
            cout << "iphone 5S\n";
        } else {
            cout << "iphone 5C\n";
        }
    }
}