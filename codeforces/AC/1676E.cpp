#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXNQ = 2e5;
int a[MAXNQ];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,q;
        cin>>n>>q;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a, a+n, greater<int>());
        for (int i=1;i<n;i++){
            a[i]+=a[i-1];
        }
        for (int i=0;i<q;i++){
            int x;
            cin>>x;
            int tmp = lower_bound(a, a+n, x)-a;
            cout<< (tmp==n ? -1 : tmp+1) <<endl;
        }
    }
}