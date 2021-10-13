#include <iostream>
#include <map>
using namespace std;
int n, k;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int index = n - 1;
        int tmove = 0;
        map<int, int> c;
        int tmp;
        for (int i = 0; i < k; i++) {
            cin >> tmp;
            if (c.count(tmp)) {
                c[tmp]++;
            } else {
                c[tmp] = 1;
            }
        }
        int ans =0;
        for (int i = n - 1; i > tmove; i--) {
            if (c.count(i)&&c[i]!=0){
                for (int j = 1;j<=c[i];j++){
                    if(i > tmove){
                        tmove+=n-i;
                        ans++;
                    } else {
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}