#include <vector>
#include <iostream>

using namespace std;

int main() {
    size_t n;

    cin >> n;
    vector<unsigned long> arr(n);
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto curr_max = arr[0];
    unsigned long turns = 0;
    for (auto x : arr) {
        if (x < curr_max) {
            turns += (curr_max - x);
        } else {
            curr_max = x;
        }
    }

    cout << turns << endl;

    return 0;
}
