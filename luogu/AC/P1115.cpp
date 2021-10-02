#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2 * 10e5;
const int MIN = -2147483647;
int main() {
    int n;
    cin >> n;

    int b[2];
    cin >> b[0];
    int ans = MIN;

    int a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        b[i & 1] = max(a, b[!(i & 1)] + a);
        ans = max(ans, b[i & 1]); 
    }
    cout << ans << endl;
    return 0;
}