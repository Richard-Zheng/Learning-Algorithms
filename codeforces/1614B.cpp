#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<deque>
using namespace std;
const int MAXN=(1e6)+1;
map<int, vector<int>> timesi; // visits -> {i}
void solve(){
    int n;
    cin>>n;
    timesi.clear();
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        timesi[tmp].push_back(i);
    }
    int t=0;
    map<int,int> ans;
    int cnt = 2;
    for(map<int, vector<int>>::iterator it=timesi.begin();it!=timesi.end();it++){
        for(vector<int>::iterator iit = it->second.begin(); iit!=it->second.end(); iit++){
            if(cnt %2==0){
                ans[*iit]=cnt/2;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}