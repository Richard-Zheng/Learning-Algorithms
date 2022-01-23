#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int MAXN = (1e6)+1;
int minw[MAXN];
int maxw[MAXN];
int main() {
    map<int, vector<int>> arr;
    int n, k;
    cin >> n >> k;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (arr.count(tmp)) {
            arr[tmp].push_back(i);
        } else {
            vector<int> v;
            v.push_back(i);
            arr[tmp] = v;
        }
    }
    for (map<int, vector<int>>::iterator it = arr.begin(); it != arr.end(); it++) {
        for(vector<int>::iterator itt = it->second.begin(); itt != it->second.end(); itt++) {
            for (int j = 0; j < k; j++) {
                if (*itt - j >= 0 && minw[*itt - j] == 0) {
                    minw[*itt - j] = it->first;
                }
            }
        }
    }
    for (map<int, vector<int>>::iterator it = arr.end(); it != arr.begin(); it--) {
        for(vector<int>::iterator itt = (*it).second.begin(); itt != (*it).second.end(); itt++) {
            int i = *itt;
            for (int j = 0; j < k; j++) {
                if (i - j >= 0 && minw[i - j] == 0) {
                    minw[i - j] = it->first;
                }
            }
        }
    }
    for (int i = 0; i <= n - k; i++) {
        cout << minw[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i <= n - k; i++) {
        cout << maxw[i] << ' ';
    }
    cout << endl;
}