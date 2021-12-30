#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    int k[n];
    ull k_low = 1, k_high = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &k[i]);
        k_high = max(k_high, static_cast<ull>(k[i]));
    }
    k_high *= t;

    while (k_low < k_high) {
        ull prods = 0, k_mid = (k_low + k_high) / 2;
        for (auto k_i : k) {
            prods += (k_mid/k_i);
        }

        if (prods < t) {
            k_low = k_mid + 1;
        }
        else {
            k_high = k_mid;
        }
    }

    cout << k_low;
    return 0;
}