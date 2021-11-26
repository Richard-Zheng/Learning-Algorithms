#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = (1e5) + 1;
ll b[MAXN];
ll c[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] += b[i];
    }
    ll tmp = 0;
    for (int i = n - 1; i >= 2; i -= 2) {
        tmp += (c[i] - c[i - 1]);
    }
    ll a = (c[n] - tmp) / 2;
    cout << a << ' ';
    for (int i = 2; i <= n; i++) {
        a = c[i - 1] - a;
        cout << a << ' ';
    }
}