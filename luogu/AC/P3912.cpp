#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e8;
bool is_prime[MAXN];
int prime[MAXN];
int prime_sieve(int n) {
    int cnt = 0;
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[++cnt] = i;  // i is the next prime
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
signed main() {
    int n;
    cin >> n;
    cout << prime_sieve(n) << endl;
}