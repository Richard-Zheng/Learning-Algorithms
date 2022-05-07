#include <bits/stdc++.h>
using namespace std;
const int MAXN = (2e5) + 1;
map<long long, int> cnt;
long long a[MAXN];
bool flag;
void dfs(long long sum) {
    if (cnt.count(sum) && cnt[sum] > 0) {
        cnt[sum]--;
    } else {
        if (sum == 1) {
            flag = false;
        } else {
            dfs(sum / 2);
            if (flag) {
                dfs((sum + 2 - 1) / 2);
            }
            
        }
    }
}
void solve() {
    cnt.clear();
    flag = true;
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (cnt.count(a[i])) {
            cnt[a[i]]++;
        } else {
            cnt[a[i]] = 1;
        }
    }
    dfs(sum);
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}