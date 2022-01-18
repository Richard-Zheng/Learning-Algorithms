#include <iostream>
#include <string>
#include<cstring>
using namespace std;
const int MAXNM = 51;
string grid[MAXNM];
bool brow[MAXNM], bcol[MAXNM];
void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    memset(brow, 0, sizeof(brow));
    memset(bcol, 0, sizeof(bcol));
    bool hasblack = false;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                hasblack = true;
                brow[i] = true;
                bcol[j] = true;
                if (i==r-1 && j==c-1){
                    zero=true;
                }
            }
        }
    }
    if(zero){
        cout<<"0\n";
        return;
    }
    if (!hasblack) {
        cout << "-1\n";
        return;
    }
    
    if (!brow[r-1] && !bcol[c-1]) {
        cout<< "2\n";
        return;
    } else {
        cout<<"1\n";return;
    }

}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}