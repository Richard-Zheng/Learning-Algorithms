#include <cstring>
#include <iostream>
#include <string>
#include<map>
using namespace std;

map<char, int> cnt;
string in;
void solve() {
    cnt.clear();
    cin >> in;
    for (int i=0;i<in.size();i++) {
        cnt[in[i]]++;
    }
    for (int j = 0; j < 2; j++) {
        for (auto const& x : cnt) {
            if (x.second == 2) {
                cout << x.first;
            }
        }
    }
    for (auto const& x : cnt) {
        if (x.second == 1) {
            cout << x.first;
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