#include <iostream>

using namespace std;

int main() {
    constexpr int M = 1'000'000'007;
    int n,x;
    cin >> n >> x;
    int values[n];
    for (int i=0; i<n; i++)
        cin >> values[i];

    int a[x+1];
    a[0] = 1;
    for (int i=1; i<=x; i++) {
        a[i] = 0;
        for (auto v : values) {
            if (v <= i)
                a[i] = (a[i] + a[i-v]) % M;
        }
    }

    cout << a[x];
}
