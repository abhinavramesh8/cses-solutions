#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    int max_len = 1, curr_start = 0;
    map<int, int> num_to_ind;
    num_to_ind[a[0]] = 0;
    for (int i=1; i<n; i++) {
        auto it = num_to_ind.find(a[i]);
        if (!((it == num_to_ind.end()) || (it->second < curr_start))) {
            max_len = max(max_len, i-curr_start);
            curr_start = (it->second)+1;
        }
        num_to_ind[a[i]] = i;
    }
    max_len = max(max_len, n-curr_start);

    cout << max_len;
    return 0;
}
