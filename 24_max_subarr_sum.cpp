#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    long long current_sum = 0, best_sum = LLONG_MIN;
    for (long long x: a) {
        current_sum = max(current_sum + x, x);
        best_sum = max(best_sum, current_sum);
    }

    cout << best_sum;
}

