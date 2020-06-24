#include <iostream>
#include <cstring>
using namespace std;
const int INF = 100000;
int A[1000];
int n;
void merge(int p, int q, int r);
void merge_sort(int p, int r);

int main() {
    memset(A, 0, sizeof(A));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cout << A[i] << " ";
    }
    cout << A[n - 1];
    
    return 0;
}

void merge(int p, int q, int r) {
    int L[q - p + 2];
    int R[r - q + 1];
    for (int i = 0; i < q - p + 1; ++i) {
        L[i] = A[p + i];
    }
    for (int i = 0; i < r - q; ++i) {
        R[i] = A[q + 1 + i];
    }
    L[q - p + 1] = INF;
    R[r - q] = INF;

    int i = 0;
    int j = 0;
    for (int k = 0; k < r - p + 1; ++k) {
        if (L[i] <= R[j]) {
            A[p + k] = L[i];
            ++i;
        } else {
            A[p + k] = R[j];
            ++j;
        }
    }
}

void merge_sort(int p, int r) {
    if (p == r) {
        return;
    }
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge(p, q, r);
}