#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1], b[n+1], p[n+1];
    int last_day = -1;
    for (int i=1; i<=n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &p[i]);
        last_day = max(last_day, b[i]);
    }
    
    long long dp[n+1][last_day+1];
    memset(dp, 0, sizeof dp);
    for (int i=1; i<=n; i++) {
        for (int d=1; d<=last_day; d++) {
            dp[i][d] = dp[i-1][d];
            if (b[i] <= d) {
                dp[i][d] = max(dp[i][d], p[i] + dp[i-1][a[i]-1]);
            }
        }
    }

    cout << dp[n][last_day];
    
    return 0;
}