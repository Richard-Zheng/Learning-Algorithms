#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 101;
int indeg[MAXN];
int main() {
    int n;
    cin>>n;

    vector<int> outflow[MAXN];
    int tmp;
    for (int i=1;i<=n;i++){
        cin>>tmp;
        while (tmp!=0){
            outflow[i].push_back(tmp);
            indeg[tmp]++;
            cin>>tmp;
        }
    }

    vector<int> s;
    vector<int> ans;
    for (int i=1;i<=n;i++){
        if (indeg[i]==0){
            s.push_back(i);
        }
    }
    int i;
    while (!s.empty()){
        i = s.back();
        s.pop_back();
        ans.push_back(i);
        for (vector<int>::iterator it = outflow[i].begin(); it != outflow[i].end(); it++) {
            indeg[*it]--;
            if (indeg[*it] == 0) {
                s.push_back(*it);
            }
        }
    }
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout<< *it <<' ';
    }
}
