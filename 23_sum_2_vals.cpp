#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int> > a(n);
    for (int i=0, e; i<n; i++) {
        cin >> e;
        a[i] = make_pair(e, i);
    }

    sort(a.begin(), a.end());
    int i=0, j=n-1, sum;
    while (i<j) {
        sum = a[i].first + a[j].first;
        if (sum == x) {
            cout << (a[i].second + 1) << ' ' << (a[j].second + 1);
            return 0;
        }
        else if (sum < x)
            i++;
        else
            j--;
    }

    cout << "IMPOSSIBLE";
    return 0;
}
