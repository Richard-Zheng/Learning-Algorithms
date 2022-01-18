#include<iostream>
#include<string>
using namespace std;
string in;
void solve(){
    cin>>in;
    int a[2];
    int addi = 0;
    for(int i=in.size()-1;i>0;i--){
        a[0]=in[i]-'0';
        a[1]=in[i-1]-'0';
        if (a[0] + a[1]>=10){
            addi = i - 1;
            break;
        }
    }
    for(int i=0;i<in.size();i++) {
        if (i==addi){
            cout<< (in[i]-'0') + (in[i+1]-'0');
            i++;
        } else {
            cout<<in[i];
        }
    }
    cout<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}