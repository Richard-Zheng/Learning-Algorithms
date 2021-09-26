#include <iostream>
#include <algorithm>
using namespace std;
int search(int sorted[], int si, int ei, int target) {
    if (si == ei) {
        return si;
    }
    int length = ei - si + 1;
    int div = length / 2;
    if (target < sorted[si + div]) {
        return search(sorted, si, si + div - 1, target);
    } else if (sorted[si + div] < target) {
        return search(sorted, si + div + 1, ei, target);
    } else {
        return si + div;
    }
}
int main() {
    int num[5] = {3, 4, 9, 10, 23};
    int target = 23;
    cout << search(num, 0, 4, target) << endl;
    return 0;
}