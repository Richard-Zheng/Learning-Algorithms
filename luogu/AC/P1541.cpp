#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 351;
const int MAXM = 121;
const int MAXB = 41;
int score[MAXN];
int n, m;
int memory[MAXB][MAXB][MAXB][MAXB];
int max_scores(int* use) {
    if (memory[use[0]][use[1]][use[2]][use[3]]) {
        return memory[use[0]][use[1]][use[2]][use[3]];
    }
    if (use[0] == 0 && use[1] == 0 && use[2] == 0 && use[3] == 0) {
        return score[1];
    } else {
        int ans = 0;
        int x = 1;  // start from 1
        for (int i = 0; i < 4; i++) {
            x += use[i] * (i + 1);
        }
        for (int i = 0; i < 4; i++) {
            if (use[i] != 0) {
                use[i]--;
                ans = max(ans, max_scores(use) + score[x]);
                use[i]++;
            }
        }
        memory[use[0]][use[1]][use[2]][use[3]] = ans;
        return ans;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }
    int b;
    int cnt[4] = {0, 0, 0, 0};
    for (int i = 1; i <= m; i++) {
        cin >> b;
        cnt[--b]++;
    }
    cout << max_scores(cnt);
}