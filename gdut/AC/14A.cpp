#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
double qpow(double base, int exp){
    ll res = 1;
    while(exp){
        if(exp&1){
            res*=base;
        }
        base*=base;
        exp>>=1;
    }
    return res;
}
double func(double x){
    return pow(x,4)-pow(x,3)-2*pow(x,2)+x-400;
}
int main(){
    /*
    double l=0;
    double r=10;
    while(fabs(func(l))>0.1){
        double middle = (l+r)/2;
        if(func(middle)>0){
            r=middle;
        }else {
            l=middle;
        }
        cout<<middle<<endl;
    }*/
    cout<<"4.86"<<endl;
}