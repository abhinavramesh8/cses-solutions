#include <bits/stdc++.h>

using namespace std;

int dp[510][510];

int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    if (a == b) {
        printf("0");
        return 0;
    }
    if (a < b) {
        swap(a, b);
    }
    dp[2][1] = 1;
    int min_cut, curr_cut;
    for (int i = 3; i <= a; i++) {
        for (int j = 1; j < i; j++) {
            min_cut = INT_MAX;
            for (int k = 1; k <= i/2; k++) {
                curr_cut = (k > j) ? dp[k][j] : dp[j][k];
                curr_cut += (((i-k) > j) ? dp[i-k][j] : dp[j][i-k]);
                min_cut = min(min_cut, curr_cut);
            }
            for (int k = 1; k <= j/2; k++) {
                curr_cut = dp[i][k] + dp[i][j-k];
                min_cut = min(min_cut, curr_cut);
            }
            dp[i][j] = 1 + min_cut;
        }
    }
    printf("%d", dp[a][b]);
    return 0;
}