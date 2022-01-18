#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
void solve() {
    string x[2];
    ll p[2];
    cin >> x[0] >> p[0] >> x[1] >> p[1];
    if (x[0].size() + p[0] != x[1].size() + p[1]) {
        if (x[0].size() + p[0] < x[1].size() + p[1]) {
            cout << "<\n";
        } else {
            cout << ">\n";
        }
        return;
    } else {
        
        int digit = max(x[0].size(), x[1].size());
        int di[2];
        for (int i = 0; i < digit; i++) {
            for (int j = 0; j < 2; j++) {
                if (x[j].size() <= i) {
                    di[j] = 0;
                } else {
                    di[j] = x[j][i] -'0';
                }
            }
            if(di[0]<di[1]){
                cout<<"<\n";
                return;
            }else if(di[0]>di[1]){
                cout<<">\n";
                return;
            }
        }
    }
    cout<<"=\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}