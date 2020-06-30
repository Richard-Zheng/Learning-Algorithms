#include <iostream>
#include <cstring>
#define max_digit 200001
using namespace std;
struct BigNum {
    int ren[max_digit]; // reversed number
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
BigNum str_to_big(string in) {
    BigNum res;
    res.len = in.length();
    for (int i = 0; i < res.len; ++i) {
        res.ren[i] = in[res.len - i - 1] - '0';
    }
    return res;
}
string big_to_str(BigNum in) {
    string out = "";
    for (int i = in.len - 1; i >= 0; --i) {
        out = out + (char)(in.ren[i] + '0');
    }
    return out;
}
int main() {
    BigNum n1, n2;
    string num1, num2;
    cin >> num1 >> num2;
    
    n1 = str_to_big(num1);

    n2 = str_to_big(num2);

    string res = big_to_str(mul(n1, n2));
    
    cout << res << endl;
    return 0;
}