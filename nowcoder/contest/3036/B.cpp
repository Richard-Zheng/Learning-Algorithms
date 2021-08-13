#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int char_to_int(char in) {
    if (in == 'S') {
        return 0;
    } else if (in == 'J') {
        return 1;
    } else if (in == 'B') {
        return 2;
    } else {
        return -1;
    }
}

int fight(int p, int n) {
    if (p == n) {
        return 0; // 平局
    }
    if (((p + 1) % 3) == n) {
        return 1; // 赢麻
    } else {
        return -1; // 输麻
    }
}

int main() {
    string sws, yzs;
    cin >> sws >> yzs;
    int sw[2], yz;
    for (int i = 0; i < 2; i++) {
        sw[i] = char_to_int(sws[i]);
    }
    yz = char_to_int(yzs[0]);

    int ans = -1;
    ans = max(ans, fight(sw[0], yz));
    ans = max(ans, fight(sw[1], yz));
    if (ans == 1) {
        cout << "pmznb" << endl;
    } else if (ans == -1) {
        cout << "ljrnb" << endl;
    } else {
        cout << "lyrnb" << endl;
    }
    return 0;
}