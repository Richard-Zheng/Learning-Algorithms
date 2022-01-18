#include<iostream>
#include<map>
#include<set>
#include<cstring>
using namespace std;
const int MAXN = (1e5)+1;
int t[MAXN];
map<int, set<int>> tree;
void solve(){
    int n;
    cin>>n;
    tree.clear();
    int vi[2];
    int root[2] = {0};
    bool nosol = false;
    int edgew2 = 0;
    for(int i=1;i<n;i++){
        cin>>vi[0]>>vi[1];
        tree[vi[0]].insert(vi[1]);
        tree[vi[1]].insert(vi[0]);
        for(int j=0;j<2;j++){
            if (tree[vi[j]].size() > 1) {
                if (root[0]==0){
                    root[0]=vi[j];
                }else if (root[1]==0){
                    root[1]=vi[j];
                    if (!tree[vi[j]].count(root[0])) {
                        nosol = true;
                    } else {
                        edgew2 = i;
                    }
                }else {
                    nosol = true;
                }
            }
        }
    }
    if (nosol) {
        cout<<"-1\n";return;
    }
    for(int i=1;i<n;i++){
        if (i==edgew2) {
            cout<<"2 ";
        } else {
            cout<<"5 ";
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