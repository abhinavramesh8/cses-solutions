#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int x[n];
    for (int &e: x) {
        scanf("%d", &e);
    }
    long long dp[n][n], left_score, right_score;
    for (int i=n-1; i>=0; i--) {
        for (int j=i; j<n; j++) {
            if (i == j) {
                dp[i][j] = x[i];
            }
            else if (i+1 == j) {
                dp[i][j] = max(x[i], x[j]);
            }
            else {
                left_score = x[i] + min(dp[i+2][j], dp[i+1][j-1]);
                right_score = x[j] + min(dp[i][j-2], dp[i+1][j-1]);
                dp[i][j] = max(left_score, right_score);
            }
        }
    }
    printf("%lld", dp[0][n-1]);
    return 0;
}