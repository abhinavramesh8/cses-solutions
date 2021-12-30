#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

long long total_weight = 0, min_diff = LLONG_MAX;
int n, max_subset_size;
vector<int> weights;

void calc_min_diff(vector<int>& subset, int weight_index) {
    if (subset.size() == max_subset_size || weight_index == n) {
        long long subset_weight = 0;
        for (auto x: subset) {
            subset_weight += x;
        }
        auto curr_diff = abs(total_weight - 2*subset_weight);
        if (curr_diff < min_diff) {
            min_diff = curr_diff ;
        }
    }
    else {
        subset.push_back(weights[weight_index]);
        calc_min_diff(subset, weight_index+1);
        subset.pop_back();
        calc_min_diff(subset, weight_index+1);
    }
}


int main() {
    cin >> n;
    max_subset_size = n/2;
    weights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        total_weight += weights[i];
    }

    vector<int> subset;
    calc_min_diff(subset, 0);
    cout << min_diff << '\n';

    return 0;
}
