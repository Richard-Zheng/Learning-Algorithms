#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXSUMK = 10e4;
bool is_prime[MAXSUMK];
int prime[MAXSUMK];
int sieve(int n) {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[1] = 0;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return cnt;
}
void solve() {
    int k;
    string n;
    cin >> k >> n;
    
}
int main() {
    int t;
    cin >> t;
    cout<<sieve(MAXSUMK)<<endl;
    while (t--) {
        solve();
    }
}