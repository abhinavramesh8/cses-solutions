#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int weights[n];
    for (int i=0; i<n; i++)
        cin >> weights[i];

    sort(weights, weights+n);
    int i=0, j=n-1, count=0;
    while (i<=j) {
        if ((weights[i]+weights[j]) <= x) {
            i++;
            j--;
        }
        else {
            j--;
        }
        count++;
    }

    cout << count;

    return 0;
}
