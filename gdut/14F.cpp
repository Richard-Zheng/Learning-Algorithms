#include <algorithm>
#include <iostream>
using namespace std;
const int MAXAB = 1000000000;
typedef long long ll;
    long long n, a, b;
ll cal(ll na){
    if(na%2!=0){
        na--;
    }
    int nb = n-na;
    return (na/2)*a+((nb+3-1)/3)*b;
}
void solve() {
    cin >> n >> a >> b;

    int l=0;
    int r=n;
    while(l<=r){
        int mid = (l+r)/2;
        if(cal(mid))
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}