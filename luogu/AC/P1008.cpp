#include <iostream>
using namespace std;
bool check(int* n) {
    bool exist[10] = {};

    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= 100; j *= 10) {
            int x = n[i] / j % 10;
            if (exist[x] || x == 0) {
                return false;
            } else {
                exist[x] = true;
            }
        }
    }
    return true;
}

int main() {
    int n[3];
    for (int i = 100; 3 * i < 1000; ++i) {
        n[0] = i * 1;
        n[1] = i * 2;
        n[2] = i * 3;

        if (check(n)) {
            cout << n[0] << " " << n[1] << " " << n[2] << endl;
        }
    }
    return 0;
}