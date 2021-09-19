#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int s[100001];
    char m = ' ';
    int size = 0;
    while (m != '\n') {
        cin >> s[size++];
        m = getchar();
    }

    int a, r;
    cin >> a >> r;
    int maxs = a + r;
    int mins = a - r;
    vector<int> ans;

    for (int i = 0; i <= size; i++) {
        if (s[i] <= maxs && s[i] >= mins) {
            ans.push_back(s[i]);
        }
    }
    // in descending order
    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}