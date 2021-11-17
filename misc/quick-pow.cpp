#include<iostream>
using namespace std;
typedef long long ll;
ll qpow(ll base, ll exp){
    int result = 1;
    while(exp){
        if(exp&1){
            result*=base;
        }
        exp>>=1;
        base*=base;
    }
    return result;
}
int main(){
    cout<<qpow(2,4)<<endl;
}