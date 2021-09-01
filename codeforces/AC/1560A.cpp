#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[1001];
    int index = 1;
    int num = 1;
    while (index <= 1000)
    {
        if (num % 3 != 0 && num % 10 != 3) {
            a[index++] = num;
        }
        num++;
    }
    
    int n;
    cin >> n;
    int in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        cout << a[in] << endl;
    }
    return 0;
}