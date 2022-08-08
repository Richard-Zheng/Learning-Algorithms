#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (s[0] != '9'){
        for (int i=0;i<n;i++){
            cout<<9-s[i]+'0';
        }
        cout<<endl;
    } else {
        bool borrow = false;
        vector<int> ans;
        for (int i=n-1;i>=0;i--){
            if (borrow) {
                if (s[i] == '0') {
                    borrow = false;
                    ans.push_back(0);
                    continue;
                }
                ans.push_back(10-s[i]+'0');
                continue;
            }
            if (1-(s[i]-'0') >= 0){
                ans.push_back(1-(s[i]-'0'));
            }else{
                borrow=true;
                ans.push_back(11-(s[i]-'0'));
            }
        }
        for (vector<int>::iterator it = ans.end(); it!=ans.begin();) {
            cout<<*(--it);
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){solve();}
}