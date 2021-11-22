#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=1e5;
const int MOD=(1e9)+7;
int main(){
    int t;
    cin>>t;
    int dp[MAXN];
    dp[1]=1;
    dp[2]=1;
    for(int i =3;i<MAXN;i++){
        dp[i]=(dp[i-1]+dp[i-1])%MOD;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
}