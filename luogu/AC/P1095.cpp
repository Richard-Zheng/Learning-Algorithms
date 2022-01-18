#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int m, s, t;
    cin >> m >> s >> t;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= t; i++) {
        s1 += 17;
        if (m >= 10) {
            s2 += 60;
            m -= 10;
        } else {
            m += 4;
        }
        s1 = max(s1, s2);
        if (s1 >= s) {
            cout << "Yes\n"
                 << i;
            return 0;
        }
    }
    cout << "No\n"
         << s1;
}