#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string in[21];
int n;
int ans = 0;
int freq[21];

int coincide_length(string s1, string s2) {
    int length = 0;
    
    int i = 0;
    int ans = 0;
    while (i < s1.length() && i < s2.length()) {
        if (s1.substr(s1.length() - 1 - i, i + 1) == s2.substr(0, i + 1)) {
            ans = i + 1;
        }
        ++i;
    }
    return ans;
}
void dfs(int x, int head, int length) {
    if (x > n || x < 1) {
        cout << "loop end with result: " << length << " head: " << in[head] << endl;
        ans = max(ans, length);
        return;
    }

    int coin_len = coincide_length(in[head], in[x]);
    //cout << "coin_len: " << coin_len << " " << in[head] << " " << in[x] << endl;
    //cout << freq[x] << " " << coin_len << " " << x << " " << head << endl;
    if (x != head && freq[x] <= 2 && coin_len > 0 && coin_len != in[x].length() && coin_len != in[head].length()) {
        cout << "! length: " << length + in[x].length() - coin_len << endl;
        ++freq[x];
        dfs(x + 1, x, length + in[x].length() - coin_len);
        dfs(x - 1, x, length + in[x].length() - coin_len);
        --freq[x];
    }
    dfs(x + 1, head, length);
    return;
}
int main() {
    memset(freq, 0, sizeof(freq));
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> in[i];
    }

    char target;
    cin >> target;

    for (int i = 1; i <= n; ++i) {
        if (in[i][0] == target) {
            dfs(1, i, in[i].length());
        }
    }
    cout << ans << endl;
    return 0;
}