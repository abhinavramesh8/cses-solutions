#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k[n];
    for (int i=0; i<n; i++)
        cin >> k[i];

    multiset<int> towers;
    int num_of_towers = 0;
    for (auto x: k) {
        auto it = towers.upper_bound(x);
        if (it == towers.end())
            num_of_towers++;
        else
            towers.erase(it);
        towers.insert(x);
    }

    cout << towers.size();

    return 0;
}
