#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    int ans = 0;
    map<char, set<int>> abci;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'b' && s[i - 1] == 'a' && s[i + 1] == 'c') {
            ans++;
            abci[s[i]].insert(i);
            abci[s[i - 1]].insert(i - 1);
            abci[s[i + 1]].insert(i + 1);
        }
    }

    int i;
    char c;
    for (int j = 0; j < q; j++) {
        cin >> i >> c;
        i--;
        if (s[i] == 'a') {
            if (i < n - 2 && s[i + 1] == 'b' && s[i + 2] == 'c') {
                ans--;
            }
        } else if (s[i] == 'b' && i < n - 1 && i >= 1 && s[i - 1] == 'a' && s[i + 1] == 'c') {
            ans--;
        } else if (s[i] == 'c' && i >= 2 && s[i - 2] == 'a' && s[i - 1] == 'b') {
            ans--;
        }
        s[i] = c;
        if (s[i] == 'a') {
            if (i < n - 2 && s[i + 1] == 'b' && s[i + 2] == 'c') {
                ans++;
            }
        } else if (s[i] == 'b' && i < n - 1 && i >= 1 && s[i - 1] == 'a' && s[i + 1] == 'c') {
            ans++;
        } else if (s[i] == 'c' && i >= 2 && s[i - 2] == 'a' && s[i - 1] == 'b') {
            ans++;
        }
        cout << ans << endl;
    }
}