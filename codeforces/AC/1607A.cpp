#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string kb, s;
        cin>>kb>>s;
        map<char,int> k;
        for(int i = 0;i<kb.length();i++){
            k[kb[i]]=i;
        }
        int ans = 0;
        for (int i = 1; i<s.length();i++){
            ans += abs(k[s[i]]-k[s[i-1]]);
        }
        cout<<ans<<endl;
    }
}