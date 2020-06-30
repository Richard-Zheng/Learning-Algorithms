#include <iostream>
#include <cstring>
#include <string>
#define max_digit 100
using namespace std;

struct BigNum {
    int ren[max_digit]; // reversed number
    int len;
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
bool big_cmp(BigNum n1, BigNum n2) { // is n1 < n2 ? (n1 == n2 true)
    if (n1.len < n2.len) {
        return true;
    } else if (n1.len > n2.len) {
        return false;
    } else {
        for (int i = n1.len - 1; i >= 0; --i) {
            if (n1.ren[i] < n2.ren[i]) {
                return true;
            } else if (n1.ren[i] > n2.ren[i]) {
                return false;
            }
        }
        return true;
    }
}

int n, k;
string in;
BigNum dp[100][100];

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cin >> in;
    
    for (int i = 1; i <= n; ++i) { // length
        for (int j = 0; j <= i - 1; ++j) { // number of multiplication
            if (j == 0) {
                dp[i][j] = str_to_big(in.substr(0, i));
                continue;
            } else if (i == j + 1) {
                dp[i][j].ren[0] = 1;
                dp[i][j].len = 1;
                for (int p = 0; p < i; ++p) {
                    dp[i][j] = mul(dp[i][j], str_to_big(in.substr(p, 1)));
                }
                //cout << "i " << i << " j " << j << " " << dp[i][j] << endl;
                continue;
            }
            BigNum ans;
            ans.ren[0] = 0;
            ans.len = 1;
            //cout << "length: " << i << " mul: " << j << endl;
            for (int k = j; k < i; ++k) {
                //cout << "cal- ("<< stoi(in.substr(0, k)) << ") " << dp[k][j - 1] << " * " << stoi(in.substr(k, i - k)) << endl;
                BigNum a = mul(dp[k][j - 1], str_to_big(in.substr(k, i - k)));
                if (big_cmp(ans, a)) { // ans < a
                    ans = a;
                }
            }
            dp[i][j] = ans;
        }
    }
    cout << big_to_str(dp[n][k]) << endl;
    return 0;
}