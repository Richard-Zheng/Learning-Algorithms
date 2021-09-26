#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        string s;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                cout << "(";
            }
            for (int j = n - i; j > 0; j--) {
                cout << "()";
            }
            for (int j = 0; j < i; j++) {
                cout << ")";
            }
            cout << endl;
        }
    }
    
    return 0;
}