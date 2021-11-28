#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
string t;
const int MAXT = 20001;
char order[MAXT];
map<char, int> appear_count;
void solve() {
    cin >> t;
    int cnt = 1;
    appear_count.clear();
    for (int i = t.size() - 1; i >= 0; i--) {
        if (appear_count.count(t[i])) {
            appear_count[t[i]]++;
        } else {
            appear_count[t[i]] = 1;
            order[cnt++] = t[i];
        }
    }
    cnt--;
    for (int i = 1; i <= cnt; i++) {
        if (appear_count[order[i]] % (cnt - i + 1)) {
            cout << "-1\n";
            return;
        } else {
            appear_count[order[i]] /= (cnt - i + 1);
        }
    }
    int k;
    for (k = 0; k < t.size(); k++) {
        if (appear_count.count(t[k])) {
            appear_count[t[k]]--;
            if (appear_count[t[k]] == 0) {
                appear_count.erase(t[k]);
                if (appear_count.size() == 0) {
                    break;
                }
            }
        }
    }
    string origin = t.substr(0, k + 1);
    string tmp = "";
    for (int i = cnt; i >= 1; i--) {
        tmp += origin;
        origin.erase(remove(origin.begin(), origin.end(), order[i]), origin.end());
    }
    if (tmp.compare(t)) {
        cout << "-1\n";
        return;
    }
    cout << t.substr(0, k + 1) << ' ';
    for (int i = cnt; i >= 1; i--) {
        cout << order[i];
    }
    cout << '\n';
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}