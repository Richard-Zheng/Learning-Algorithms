#include <iostream>
using namespace std;
int main() {
    int T, now;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n;
        cin >> n;
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            cin >> now;
            ans = ans > now ? ans : now;
        }
        cout << ans << endl;
    }
}