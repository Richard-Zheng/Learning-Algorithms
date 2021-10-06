#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    int suffix[1000] = {0};
    int countone[1000] = {0};
    int countzero[1000] = {0};
    int tmp = numeric_limits<int>::min();
    for (int i = n; i > 0; i--) {
        if (s[i] == '0') {
            countzero[i] = countzero[i + 1] + 1;
            countone[i] = countone[i + 1];
        } else {
            countzero[i] = countzero[i + 1];
            countone[i] = countone[i + 1] + 1;
        }
        if (tmp < (countzero[i] - countone[i])) {
            tmp = countzero[i] - countone[i];
            suffix[i] = i;
        } else {
            suffix[i] = suffix[i + 1];
        }
    }

    int ans = numeric_limits<int>::max();
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            count++;
        } else if (i == n) {
            ans = min(ans, count);
        } else {
            while (s[i + 1] != '0') {
                i++;
            }
            int t = count + (countzero[i] - countzero[suffix[i + 1] + 1]) + countone[suffix[i + 1]];
            ans = min(ans, t);
        }
    }
    cout << ans << endl;
    return 0;
}