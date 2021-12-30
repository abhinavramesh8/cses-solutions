#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int arrival = 0;
constexpr int departure = 1;

int main() {
    int n;
    cin >> n;
    vector<tuple<int,int,int> > times;
    for(int a,b,i=0; i<n; i++) {
        cin >> a >> b;
        times.push_back(make_tuple(a,arrival,i));
        times.push_back(make_tuple(b,departure,i));
    }

    sort(times.begin(), times.end());
    vector<int> free_rooms;
    int allotments[n];
    int max_rooms = 0;
    for (auto t: times) {
        int customer = get<2>(t);
        if (get<1>(t) == arrival) {
            if (free_rooms.empty()) {
                allotments[customer] = ++max_rooms;
            }
            else {
                allotments[customer] = free_rooms.back();
                free_rooms.pop_back();
            }
        }
        else {
            free_rooms.push_back(allotments[customer]);
        }
    }
    
    cout << max_rooms << '\n';
    for (auto room: allotments) {
        cout << room << ' ';
    }
}
