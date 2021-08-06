#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n; // 小朋友数量
    int m; // 最多买多少玩具
    int k; // 一共卖k种玩具
    cin >> n >> m >> k;

    int a[1 << 16];
    for (int i = 0, tp; i < n; i++)
    {
        cin >> tp;
        if (tp != 0)
        {
            for (int j = 0, tmp; j < tp; j++)
            {
                cin >> tmp;               //第一个数字 a代表第 i 个小朋友想玩的玩具数量，
                a[i] |= (1 << (tmp - 1)); //用二进制来表达出某个娃子要的玩具
            }                             //接下来有 a个数字，代表这 a个玩具的编号。
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << k); i++)
    {
        int sum = 0;
        bool overflow = false;
        for (int j = 0; j < k; j++)
        {
            if (i & (1 << j))
            {
                sum++;
            }
            if (sum > m)
            {
                overflow = true;
                break;
            }
        }
        if (overflow)
            continue;
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & a[j]) == a[j])
            {
                sum++;
            }
        }
        ans = max(sum, ans);
    }
    cout << ans << endl;
}