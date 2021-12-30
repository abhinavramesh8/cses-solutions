#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];
char grid[1010][1010];

const int M = 1'000'000'007;

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%s", grid[i]);
    }

    if (grid[0][0] == '.') {
        dp[0][0] = 1;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == '*') {
                continue;
            }
            if (i > 0) {
                dp[i][j] = dp[i-1][j];
            }
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % M;
            }
        }
    }

    printf("%d", dp[n-1][n-1]);
    return 0;
}