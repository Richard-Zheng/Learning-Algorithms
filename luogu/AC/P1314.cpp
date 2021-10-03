#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXNM = 200001;
ll n, m, s;
ll w[MAXNM], v[MAXNM], l[MAXNM], r[MAXNM];
ll prenum[MAXNM];
ll preval[MAXNM];
ll y, sum;
bool check(int W)
{
    y = 0;
    sum = 0;
    memset(prenum, 0, sizeof(prenum));
    memset(preval, 0, sizeof(preval));
    
    // 处理前缀和
    for (int i = 1; i <= n; i++)
    {
        if (w[i] >= W)
        {
            prenum[i] = prenum[i - 1] + 1;
            preval[i] = preval[i - 1] + v[i];
        }
        else
        {
            prenum[i] = prenum[i - 1];
            preval[i] = preval[i - 1];
        }
    }

    // 计算 y
    for (int i = 1; i <= m; i++)
    {
        y += (prenum[r[i]] - prenum[l[i] - 1]) * (preval[r[i]] - preval[l[i] - 1]);
    }
    sum = abs(y - s);
    if (y > s)
    {
        return true; // W 选的过小
    }
    else
    {
        return false; // W 选的过大
    }
}
int main()
{
    cin >> n >> m >> s;

    ll maxw = -1, minw = 1 << 30;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        maxw = max(maxw, w[i]);
        minw = min(minw, w[i]);
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
    }
    int left = minw - 1;
    int right = maxw + 2;
    int mid;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    // 二分搜索 求出最小的 |s - y|
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (check(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        if (sum < ans)
        {
            ans = sum;
        }
    }
    cout << ans << endl;
    return 0;
}