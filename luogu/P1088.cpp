#include <iostream>
using namespace std;
void add(int i, int num);
void swap(int x, int y);
int find(int num);
void reverse(int x);

int finger[10001];
int n, m;
int main() {
    cin >> n >> m;

    for (int i = n; i >= 1; --i) { // reversive storing numbers
        cin >> finger[i];
    }

    add(1, m);

    for (int i = n; i >= 1; --i) {
        cout << finger[i] << " ";
    }
    return 0;
}

void add(int i, int num) {
    // we assume that values from 1 to i are all sorted to
    // reach the maximum val that it can present

    if (i == 1) {
        add(i + 1, num);
        return;
    }

    if (num == 0) {
        return;
    }
    
    if (finger[i - 1] > finger[i]) {
        // then 1 ~ i - 1 aren't reach the max val
        cout << "swap " << finger[i] << " " << finger[i] + 1 << " , then reverse " << i - 1 << endl;

        swap(i, find(finger[i] + 1));
        reverse(i - 1);

        add(1, num - 1);
    } else {
        add(i + 1, num);
    }
}

void swap(int x, int y) {
    int temp = finger[x];
    finger[x] = finger[y];
    finger[y] = temp;
}

int find(int num) {
    for (int i = 1; i <= n; ++i) {
        if (finger[i] == num) {
            return i;
        }
    }
    return -1;
}

void reverse(int x) {
    for (int i = 1; i <= x / 2; ++i) {
        swap(i, x - i + 1);
    }
    return;
}
