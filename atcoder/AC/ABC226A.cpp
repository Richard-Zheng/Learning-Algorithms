#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    double x;
    cin >> x;
    int ix = (int)x;
    if ((x - ix) >= 0.5) {
        cout << ix + 1 << endl;
    } else {
        cout << ix << endl;
    }
}