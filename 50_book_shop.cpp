#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x;
    scanf("%d %d", &n, &x);
    int h[n+1], s[n+1];
    for (int i=1; i<=n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i=1; i<=n; i++) {
        scanf("%d", &s[i]);
    }

    int dp[n+1][x+1];
    memset(dp, 0, sizeof dp);
    for (int i=1; i<=n; i++) {
        for (int p=1; p<=x; p++) {
            dp[i][p] = dp[i-1][p];
            if (h[i] <= p) {
                dp[i][p] = max(dp[i][p], s[i] + dp[i-1][p-h[i]]);
            }
        }
    }

    printf("%d", dp[n][x]);
    return 0;
}