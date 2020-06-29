#include <iostream>
#include <cstring>
#define max_digit 200001
using namespace std;
struct BigNum {
    long long ren[max_digit]; // reversed number
    long long len;
};
BigNum mul(BigNum n1, BigNum n2) {
    BigNum res;
    if (n1.ren[n1.len - 1] == 0 || n2.ren[n2.len - 1] == 0) {
        res.ren[0] = 0;
        res.len = 1;
        return res;
    }
    
    memset(res.ren, 0, sizeof(res));
    for (int j = 0; j < n2.len; ++j) {
        for (int i = 0; i < n1.len; ++i) {
            res.ren[i + j] += n1.ren[i] * n2.ren[j];
        }
    }

    res.len = n1.len + n2.len - 1;
    for (int i = 0; i < n1.len + n2.len - 1; ++i) {
        res.ren[i + 1] += res.ren[i] / 10;
        res.ren[i] %= 10;
    }

    while (res.ren[res.len])
    {
        ++res.len;
        res.ren[res.len + 1] = res.ren[res.len] / 10;
        res.ren[res.len] %= 10;
    }
    return res;
}
int main() {
    BigNum n1, n2;
    string num1, num2;
    cin >> num1 >> num2;
    
    n1.len = num1.length();
    for (int i = 0; i < n1.len; ++i) {
        n1.ren[i] = num1[n1.len - i - 1] - '0';
    }

    n2.len = num2.length();
    for (int i = 0; i < n2.len; ++i) {
        n2.ren[i] = num2[n2.len - i - 1] - '0';
    }

    BigNum res = mul(n1, n2);
    for (int i = res.len - 1; i >= 0; --i) {
        cout << res.ren[i];
    }
    cout << endl;
    return 0;
}