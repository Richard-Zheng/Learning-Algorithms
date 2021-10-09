#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    int m[100001] = {0};
    m[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= i - k && j >= 0; j--) {
            m[i] += m[j];
            m[i] %= 100003;
        }
    }
    cout << m[n] << endl;
    return 0;
}