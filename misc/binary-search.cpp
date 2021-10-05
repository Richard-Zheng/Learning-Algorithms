#include <iostream>
#include <algorithm>
using namespace std;
int binary_search(int array[], int n, int value) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = left + ((right - left) >> 1);
        
        if (array[middle] > value) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    if (left < n && array[left] == value) {
        return left;
    }
    return -1;
}
int main() {
    int num[1] = {3};
    cout << binary_search(num, 1, 3) << endl;
    return 0;
}