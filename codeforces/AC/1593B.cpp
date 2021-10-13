#include <iostream>
#include <limits>
#include <string>
using namespace std;
string in;
int find(char target, char append1, char append2) {
    int index = -1;
    for (int i = in.length() - 1; i >= 0; i--) {
        if (in[i] == target) {
            index = i;
            break;
        }
    }
    if(index==-1){
        return numeric_limits<int>::max();
    }
    for (int i = index - 1; i >= 0; i--) {
        if (in[i] == append1 || in[i] == append2) {
            return index - i - 1 + (in.length() - index - 1);
        }
    }
    return numeric_limits<int>::max();
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> in;
        cout << min(find('0', '0', '5'), find('5', '2', '7')) << endl;
    }
}