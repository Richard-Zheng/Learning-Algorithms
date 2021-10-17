#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MAXN=3e5;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        bool flipped[MAXN];
        int ans = 0;
        vector<int> flip;
        for (int i = 0; i < n; i++) {
            if (!flipped[i] || s[i] != c) {
                for (int j = i; j < n; j += i){
                    flipped[j]=true;
                }
                ans++;
                flip.push_back(i+1);
            }
            
        }
        cout << ans << endl;
        for (int i =0;i<flip.size();i++){
            cout << flip[i]<<' ';
        }
        cout<<endl;
    }
}