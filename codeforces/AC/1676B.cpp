#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 51;
int a[MAXN];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int ans = 0;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a, a+n);
        for (int i=1;i<n;i++){
            ans += a[i]-a[0];
        }
        cout<<ans<<endl;
    }
}