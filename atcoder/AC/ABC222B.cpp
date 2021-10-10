#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5;
int main() {
    int n, p;
    cin >> n >> p;
    int tmp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (tmp < p) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}