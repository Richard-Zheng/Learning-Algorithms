#include <iostream>
#include<string>
using namespace std;
void solve() {
    string in;
    cin >> in;
    char prev = '1';
    int cnt = 0;
    for (int i = 0; i < in.length();i++){
        if (in[i] !=prev){
            cnt++;
            if(cnt >=3) {
                cout <<'2'<<endl;
                return;
            } else {
                prev=in[i];
            }
        }
    }
    if (cnt==0) {cout <<'0'<<endl;} else {cout<<'1'<<endl;}
}
int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}