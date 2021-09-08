#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    
    string n;
    for (int i = 0; i < t; i++) {
        cin >> n;

        int a = 0;
        int b = 0;
        for (int j = 0; j < n.length(); j++) {
            if (j % 2 == 0 || j == 0) {
                a += ((n[n.length() - 1 - j] - '0') * pow(10, j / 2));
            } else {
                b += ((n[n.length() - 1 - j] - '0') * pow(10, j / 2));
            }
        }
        cout << (a + 1) * (b + 1) - 2 << endl;
    }
    return 0;
}