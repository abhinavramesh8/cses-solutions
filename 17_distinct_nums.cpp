#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int num_of_distinct = 1;
    for (int i=0; i<n-1; i++) {
        if (arr[i] != arr[i+1]) {
            num_of_distinct++;
        }
    }

    cout << num_of_distinct;
}


