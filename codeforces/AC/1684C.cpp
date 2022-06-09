#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int MAXNM = 2e5 + 1;
set<int> decidx;
int flag[MAXNM];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n+1, vector<int> (m+1,0));
    decidx.clear();
    vector<int> tmp(m+1, 0);
    for (int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
        for (int j=0;j<=m;j++){
            tmp[j] = matrix[i][j];
        }
        sort(tmp.begin(), tmp.end());
        for (int j=1;j<=m;j++){
            if (matrix[i][j] != tmp[j]){
                decidx.insert(j);
            }
        }
    }
    if (decidx.size() == 0){
        cout<<"1 1\n";
        return;
    }
    if (decidx.size() > 2){
        cout<<"-1\n";
        return;
    }
    vector<int> deci(decidx.begin(), decidx.end());
    for (int i=1;i<=n;i++){
        swap(matrix[i][deci[0]], matrix[i][deci[1]]);
    }
    bool flag = true;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (matrix[i][j-1]> matrix[i][j]){
                flag = false;
            }
        }
    }
    if (flag){
        cout<<deci[0]<<' '<<deci[1]<<'\n';
    }else{
        cout<<"-1\n";
    }
}
int main(){
    int t;
    cin>>t;
    while (t--){solve();}
}