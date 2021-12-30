#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int, int> > times(n);
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        times[i] = make_pair(b, a);
    }

    sort(times.begin(), times.end());
    int count = 1, prev_end = times[0].first;
    for (int i=1; i<n; i++) {
        if (times[i].second >= prev_end) {
            count++;
            prev_end = times[i].first;
        }
    }

    cout << count;

    return 0;
}
