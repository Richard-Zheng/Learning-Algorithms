#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string in;
        cin >> in;
        int y = 0;
        int n = 0;
        int half = in.length() / 2;
        for (int j = 0; j < in.length(); j++) {
            if (in[j] == 'Y' || in[j] == 'y') {
                y++;
            } else if (in[j] == 'N' || in[j] == 'n') {
                n++;
            }
        }
        if (y >= half) {
            cout << "pmznb" << endl;
        } else if (n >= half) {
            cout << "lyrnb" << endl;
        } else {
            cout << "wsdd" << endl;
        }
    }
}