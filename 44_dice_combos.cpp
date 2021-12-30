#include <iostream>
#include <vector>

using namespace std;

constexpr int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> ways(n+1, 0);
    ways[0] = 1; 
    for (int i=1; i<=n; i++) {
        int outcome_bound = min(6, i);
        for (int j=1; j<=outcome_bound; j++) {
            ways[i] = (ways[i] + ways[i-j]) % M;
        }
    }

    cout << ways[n];
    return 0;
}
