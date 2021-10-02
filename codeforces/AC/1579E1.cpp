#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <deque>
using namespace std;
const int MAXN = 2 * 10e5;
int main() {
    int t;
    cin >> t;

    int n;
    int* p = (int*) malloc(MAXN * sizeof(int));
    while (t--) {
        deque<int> ans;
        cin >> n;

        int tmp;
        cin >> tmp;
        ans.push_back(tmp);
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            if (p[i] > ans.front()) {
                ans.push_back(p[i]);
            } else {
                ans.push_front(p[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}