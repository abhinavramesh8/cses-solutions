#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);
    int median = a[n/2];
    long long cost = 0;
    for (auto x: a) {
        cost += abs(median - x);
    }

    cout << cost;

    return 0;
}
