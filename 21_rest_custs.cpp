#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int arrival = 0;
constexpr int departure= 1;

int main() {
    int n;
    cin >> n;
    int a, b;
    vector<pair<int, int> > times;
    times.reserve(n);
    while (n--) {
        cin >> a >> b;
        times.push_back(make_pair(a, arrival));
        times.push_back(make_pair(b, departure));
    }

    sort(times.begin(), times.end());
    int curr_custs = 0, max_custs = 0;
    for (auto t: times) {
        if (t.second == arrival) {
            curr_custs++;
            max_custs = max(curr_custs, max_custs);
        }
        else
            curr_custs--;
    }

    cout << max_custs;

    return 0;
}
