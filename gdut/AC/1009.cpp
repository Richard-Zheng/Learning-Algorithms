#include <cstdio>
int main() {
    int i, j, cnt, k, N, K, a[5555];
    scanf("%d%d", &N, &K);
    int ans = 0;
    for (i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    long long pre[5555];
    pre[0] = 0;
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (i = 1; i <= N; i++) {
        for (j = i + 1; j <= N; j++) {
            if ((pre[j] - pre[i - 1]) % K == 0) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}