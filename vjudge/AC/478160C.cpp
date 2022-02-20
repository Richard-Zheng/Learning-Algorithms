#include <cstring>
#include <iostream>
using namespace std;
const int MAXNM = 30000 + 500 + 10;
int ufset[MAXNM];
int find(int x) {
    return ufset[x] == x ? x : ufset[x] = find(ufset[x]);
}
void unite(int x, int y) {
    ufset[find(x)] = find(y);
    return;
}
int main() {
    int n, m;
    cin >> n >> m;
    while (n + m != 0) {
        // init
        for (int i = 0; i < MAXNM; i++) {
            ufset[i] = i;
        }

        for (int i = n; i < n + m; i++) {
            // #i association
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int stu;
                cin >> stu;
                unite(stu, i);
            }
        }

        int tar = find(0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == tar) {
                ans++;
            }
        }
        cout << ans << endl;

        cin >> n >> m;
    }
}