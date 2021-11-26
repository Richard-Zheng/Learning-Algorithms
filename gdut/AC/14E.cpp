#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
const int MOD = (1e9) + 7;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        n -= 2;
        if (n % 2 == 0) {
            cout << (n / 2) * (n - 1) % MOD << endl;
        } else {
            cout << n * ((n - 1) / 2) % MOD << endl;
        }
    }
}