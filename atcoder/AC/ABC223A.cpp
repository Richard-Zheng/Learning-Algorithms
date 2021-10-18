#include <iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    if (x % 100 || x == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}