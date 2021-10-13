#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e8;
bool is_prime[MAXN];
int prime[MAXN];
int cnt = 0;
void prime_sieve(int n) {
    memset(is_prime, 1, sizeof(is_prime));  // make all number initially be prime
    is_prime[1] = 0;                        // 1 is not prime
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
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    prime_sieve(n);
    while (q--) {
        int k;
        cin >> k;
        cout << prime[k] << '\n';
    }
    return 0;
}