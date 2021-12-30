#include <iostream>
#include <climits>

using namespace std;

int n;

int main() {
    cin >> n;
    int a[n];
    a[0] = 0;
    for (int i=1; i<=9; i++)
        a[i] = 1;

    for (int i=10; i<=n; i++) {
        int min_steps = INT_MAX;
        for (auto x=i; x; x /= 10) {
            int digit = x % 10;
            if (digit)
                min_steps = min(min_steps, a[i-digit]+1);
        }
        a[i] = min_steps;
    }

    cout << a[n];
    return 0;
}
