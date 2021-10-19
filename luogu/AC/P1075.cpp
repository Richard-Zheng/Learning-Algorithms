#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2 * 1e9;
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cout << n / i << endl;
            return 0;
        }
    }
    return 0;
}