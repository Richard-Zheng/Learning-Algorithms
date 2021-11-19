#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXNM = 3e4;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << ((n * m) + 3 - 1) / 3 << '\n';
    }
}