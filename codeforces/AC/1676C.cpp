#include<iostream>
#include<limits>
#include<string>
using namespace std;
const int MAXN = 51;
string s[MAXN];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        for (int i=0;i<n;i++){
            cin>>s[i];
        }
        int ans = numeric_limits<int>::max();
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int tmp = 0;
                for (int k=0;k<m;k++){
                    tmp += abs(s[i][k]-s[j][k]);
                }
                ans = min(ans, tmp);
            }
        }
        cout<<ans<<endl;
    }
}