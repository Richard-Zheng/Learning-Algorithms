#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll MAXK = (ll) 10e9;
int main() {
    vector<ll> ts;
    for (ll p = 1; p * p <= MAXK; p++) {
        ts.push_back(p * p);
    }
    
    int t;
    cin >> t;
    int k;
    for (int i = 0; i < t; i++) {
        cin >> k;
        if (k == 1) {
            cout << "1 1" << endl;
            continue;
        }

        for (int q = 0; q < ts.size(); q++) {
            if (k <= ts[q]) {
                int half = (ts[q] - ts[q - 1] - 1) / 2;
                int diagonal = ts[q] - half;
                if (k <= diagonal) { // c = q + 1
                    cout << q + 1 - (diagonal - k) << " " << q + 1 << endl;
                } else {
                    cout << q + 1 << " " << half + 1 - (k - diagonal) << endl;
                }
                break;
            }
        }
    }
    return 0;
}