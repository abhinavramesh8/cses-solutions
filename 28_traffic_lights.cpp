#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    set<int> positions;
    multiset<int> passages;
    positions.insert(0);
    positions.insert(x);
    passages.insert(x);
    for(int p; n--;) {
        cin >> p;
        auto it = positions.insert(p).first;
        int prev_pos = *(prev(it));
        int next_pos = *(next(it));
        passages.erase(passages.find(next_pos - prev_pos));
        passages.insert(next_pos - p);
        passages.insert(p - prev_pos);
        cout << (*(prev(passages.end()))) << " ";
    }

    return 0;
}
