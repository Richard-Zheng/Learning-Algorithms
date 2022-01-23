#include <iostream>
#include <string>
using namespace std;
string s;
int vis[7];
char now[7];
void dfs(int n) {
    if (n >= s.size()) {
        for (int i = 0; i < s.size(); i++) {
            cout << now[i];
        }
        cout << endl;
    }
    for (int i = 0; i < s.size(); i++) {
        if (!vis[i]) {
            vis[i] = true;
            now[n] = s[i];
            dfs(n + 1);
            vis[i] = false;
        }
    }
}
int main() {
    cin >> s;
    dfs(0);
}