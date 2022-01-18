#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 150001;
int a[MAXN];
map<int, vector<int>> inx;
void solve() {
    inx.clear();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        inx[a[i]].push_back(i);
    }
    int ans = -1;
    for(auto const&x : inx) {
        if (x.second.size() >= 2) {
            for (int j = 0; j<x.second.size()-1; j++){
                ans = max(ans, x.second[j] + (n - x.second[j+1]));
            }
        }
    }
    cout<<ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){solve();}
}

// 1 2 3 5 3 1