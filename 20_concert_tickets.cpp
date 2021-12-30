#include <iostream>
#include <set>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    multiset<int, greater<int> > tickets;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        tickets.insert(x);
    }
    while(m--) {
        cin >> x;
        auto it = tickets.lower_bound(x);
        if (it == tickets.end()) {
            cout << "-1";
        }
        else {
            cout << *it;
            tickets.erase(it);
        }
        cout << '\n';
    }

    return 0;   
}
