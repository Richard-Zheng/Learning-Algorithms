#include<iostream>
#include<map>
using namespace std;
const int MAXN=1e6;
int bz[MAXN];
int main(){
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        bz[tmp]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<bz[i]<<' ';
    }
}