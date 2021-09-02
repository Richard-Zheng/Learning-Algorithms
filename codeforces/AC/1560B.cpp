#include <iostream>
#include <algorithm>
using namespace std;
bool validate(int a, int b) {
    return 2 * a <= b;
}
int find_max(int a, int b) {
    return b + b - a - a;
}
int find_opposite(int a, int b, int c) {
    return (c + b - a) % find_max(a, b);
}
int main() {
    int n;
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a > b) {
            swap(a, b);
        } // make a < b
        
        if (!validate(a, b) || c > find_max(a, b)) {
            cout << "-1" << endl;
            continue;
        }
        int ans = find_opposite(a, b, c);
        if (ans == 0) ans = b + b - a - a;
        cout << ans << endl;
    }
    return 0;
}