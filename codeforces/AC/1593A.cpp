#include <algorithm>
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
ll in[3], ans[3];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> in[0] >> in[1] >> in[2];
        ll* maxin = max_element(in, in + 3);
        memset(ans, 0, sizeof(ans));
        int cntmax = 0;
        for (int i = 0; i < 3; i++) {
            if (in[i] == maxin[0]) {
                cntmax++;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (in[i] == maxin[0]) {
                if (cntmax >= 2) {
                    cout << "1";
                } else {
                    cout << "0";
                }
            } else {
                int n1 = (i + 1) % 3;
                int n2 = (i + 2) % 3;
                cout << max(in[n1] - in[i] + 1, in[n2] - in[i] + 1);
            }
            if (i != 2) {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}