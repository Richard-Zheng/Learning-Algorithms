#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 10e3;
int main() {
    int t;
    cin >> t;

    long long n, h;
    long long tmp;
    vector<long long> a;
    while (t--) {
        a.clear();
        cin >> n >> h;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        int two = a[n - 1] + a[n - 2];
        if (h <= a[n - 1]) {
            cout << "1" << endl;
            continue;
        }
        if (h <= two) {
            cout << "2" << endl;
            continue;
        }
        int ans = h / two;
        h -= ans * two;
        int count = 0;
        while (h > 0) {
            h -= a[n - 1 - (count & 1)];
            count++;
        }
        cout << (ans * 2) + count << endl;
    }
    return 0;
}