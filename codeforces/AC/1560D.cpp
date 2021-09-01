#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const long long P2LIM = (long long) 2e18;
int solve(string s, string t) {
    int tp = 0;
    int sp = 0;
    int token = 0;
    while (sp < s.length() && tp < t.length())
    {
        if (s[sp] == t[tp]) {
            token++;
            tp++;
        }
        sp++;
    }
    
    return (int)s.length() - token + (int)t.length() - token;
}
int main() {
    vector<string> ts;
    for (long long p2 = 1; p2 <= P2LIM; p2 *= 2) {
        ts.push_back(to_string(p2));
    }

    int t;
    cin >> t;
 
    while (t--)
    {
        string n;
        cin >> n;
        int ans = n.length() + 1; // set to max
        for (auto p2 : ts) {
            ans = min(ans, solve(n, p2));
        }
        cout << ans << endl;
    }
    
    return 0;
}