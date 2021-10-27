#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int pwd[3][2];
    set<int> p[3];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {  // 第几位
            cin >> pwd[j][i];

            pwd[j][i]--;
            p[j].insert(pwd[j][i]);
        }
    }
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 2; i++) {
            for (int marg = -2; marg <= 2; marg++) {
                p[j].insert((n + pwd[j][i] - marg) % n);
            }
        }
    }
    cout<<((int)p[0].size())*((int)p[1].size())*((int)p[2].size())<<endl;
}
int main() {
    //cout << -1%9<<endl;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}