#include <bits/stdc++.h>

using namespace std;

constexpr int M = 1'000'000'007;

int main() {
    int n,x;
    cin >> n >> x;
    int coins[n];
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }
    sort(coins, coins+n);
    int dp[n][x+1], coin;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int v=0; v<=x; v++) {
            if (i) {
                dp[i][v] = dp[i-1][v];
            }
            if (coins[i] <= v) {
                dp[i][v] = (dp[i][v] + dp[i][v-coins[i]]) % M;
            }
        }
    }
    cout << dp[n-1][x];
    return 0;
}
