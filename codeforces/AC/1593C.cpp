#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int n, k;
const int MAXK = 4e5;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int index = n - 1;
        int tmove = 0;
        int c[MAXK];
        int tmp;
        for (int i = 0; i < k; i++) {
            cin >> c[i];
        }
        sort(c, c + k);
        int ans = 0;
        for (int i = k - 1; c[i] > tmove && i >= 0; i--) {
            tmove += n - c[i];
            ans++;
        }
        cout << ans << endl;
    }
}