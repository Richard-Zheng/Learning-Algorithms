#include <algorithm>
#include <iostream>
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    //int tmp=min(min(a,b),c);
    //a-=tmp;b-=tmp;c-=tmp;

    int sum = a + (b * 2) + (c * 3);
    int tmp = 0;
    int ans = sum - 2 * (tmp);

    int xc = min(c, sum/3);
    tmp += xc * 3;
    int xb = min(b, (sum - 2 * tmp) / 2);
    tmp += xb * 2;
    int xa = min(a, (sum - 2 * tmp));
    tmp += xa;

    ans = sum - 2 * tmp;
    cout << abs(ans) << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}