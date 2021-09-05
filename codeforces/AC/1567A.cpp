#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;

    string input;
    int width;
    for (int i = 0; i < t; i++) {
        cin >> width;
        cin >> input;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == 'U') {
                cout << 'D';
            } else if (input[i] == 'D') {
                cout << 'U';
            } else {
                cout << input[i];
            }
        }
        cout << endl;
    }
    return 0;
}