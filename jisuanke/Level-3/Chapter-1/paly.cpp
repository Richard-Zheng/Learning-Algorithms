#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int totalWeight; // 剩下的牌的总重量,
int amount; // 这副牌有多少张
int max_weight; // 这副牌的总重量
int weightPerCard[101];
int f[10005]; // f[j]为重量为j的可能性 0:达不到 1:有一解 -1:有多解
int pre[10005]; // 一重量下最晚放的牌的编号

int main() {
    freopen("paly.in", "r", stdin);
    freopen("paly.out", "w", stdout);
    cin >> totalWeight >> amount;
    for (int i = 1; i <= amount; i++) {
        cin >> weightPerCard[i];
        max_weight += weightPerCard[i];
    }
    
    f[0] = 1;
    for (int i = 1; i <= amount; i++) {
        for (int j = max_weight; j >= weightPerCard[i]; j--) {
            if (f[j - weightPerCard[i]] > 0) {
                if (f[j] == 1) {
                    f[j] = -1; // multiple solutions
                } else if (f[j] == 0) {
                    f[j] = 1;
                    pre[j] = i; // used for backtracking
                }
            }
        }
    }
    f[0] = 0; // in case totalWeight = 0

    if (f[totalWeight] <= 0) { // no solution or multiple solutions
        cout << f[totalWeight] << endl;
    } else {
        int ans[105] = {0};
        int count = 0;
        int current = max_weight - totalWeight;
        while (current > 0) {
            ans[++count] = pre[current];
            current -= weightPerCard[pre[current]];
        }
        for (int i = count; i >= 1; i--) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
