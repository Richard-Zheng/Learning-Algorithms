#include <cstring>
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXNM = (1e5) + 1;
int cnt[MAXNM];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int m1 = max(abs(i-n)+abs(j-m), i-1+j-1);
            int m2 = max(i-1+abs(j-m), abs(i-n)+j-1);
            m1 = max(m1,m2);
            cnt[m1]++;
        }
    }
    for(int i=1;i<n+m;i++) {
        for(int j=cnt[i]; j>0; j--){
            cout<<i<<' ';
        }
    }
    cout<<endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}