#include <iostream>
using namespace std;
const int MAXN = (1e5) + 1;
long long presum[MAXN];
int main() {
    int n, q;
    cin >> n >> q;
    presum[0] = 0;
    int in;
    for (int i = 1; i <= n; i++) {
        cin >> in;
        presum[i] = presum[i - 1] + in;
    }
    int f, t;
    for (int i = 1; i <= q; i++) {
        cin >> f >> t;
        cout << presum[t] - presum[f - 1] << endl;
    }
}