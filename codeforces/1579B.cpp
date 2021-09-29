#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
typedef long long ll;
int n;
int counter;
vector<ll> a;
void shift(int l, int r, int d) {
    counter++;
    rotate(a.begin() + l - 1, a.begin() + l - 1 + d, a.begin() + r);
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            a.push_back(tmp);
        }

        stringstream ans;
        counter = 0;
        int l;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                l = i;
                break;
            }
            if (i == n - 1) {
                l = n;
            }
        }
        while (l != n) {
            int r;
            for (int i = l; i < n; i++) {
                if (a[i - 1] > a[i]) {
                    r = i + 1;
                }
            }
            shift(l, r, 1);
            ans << l << " " << r << " 1" << endl;

            for (int i = 1; i < n; i++) {
                if (a[i - 1] > a[i]) {
                    l = i;
                    break;
                }
                if (i == n - 1) {
                    l = n;
                }
            }
        }
        
        //rotate(a.begin() + 1 - 1, a.begin() + 1 - 1 + 1, a.begin() + 2);

        cout << counter << endl << ans.str();
    }
    return 0;
}