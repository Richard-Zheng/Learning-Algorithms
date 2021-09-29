#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 10e5;
int main() {
    int t;
    cin >> t;

    int n;
    map<int, int> p;
    while (t--) {
        cin >> n;

        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            p[tmp] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            p[tmp] = i;
        }

        int l;
        for (int i = 2 * n; i >= 1; i--) {

        }
    }
    return 0;
}