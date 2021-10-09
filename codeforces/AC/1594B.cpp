#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const long long MAX = 1e9 + 7;
long long pow_h(long long a, int n) {
    long long s = 1;
    for (int i = 1; i <= n; i++) {
        s %= MAX;
        s *= a;
    }
    //cout << s % MAX << endl;
    return s % MAX;
}
int main() {
    int t;
    cin >> t;
    long long n, k;
    while (t--) {
        cin >> n >> k;
        long long ans = 0;
        int count = 0;
        for (int i = 1; i <= k; i <<= 1) {
            long long flag = k & i;
            //cout << flag << " " << count << endl;
            if (flag) {
                ans += pow_h(n, count);
                ans %= MAX;
            }
            count++;
        }
        cout << ans << endl;
    }
    return 0;
}