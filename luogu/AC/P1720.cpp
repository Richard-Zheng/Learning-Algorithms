#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 48;
int main() {
    ll f[MAXN] = {0};
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= MAXN; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    int n;
    cin >> n;
    cout << f[n] << ".00" << endl;
}