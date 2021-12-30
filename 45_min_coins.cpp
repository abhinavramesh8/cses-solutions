#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_coins(int x, vector<int>& coins, vector<int>& values) {
    if (coins[x] != -2)
        return coins[x];
    int min_coins = INT_MAX;
    for (auto value: values) {
        int curr_coins = (value > x ? -1 : get_coins(x-value, coins, values));
        if (curr_coins >= 0) {
            curr_coins++;
            if (curr_coins < min_coins)
                min_coins = curr_coins;
        }
    }
    if (min_coins == INT_MAX)
        min_coins = -1;
    coins[x] = min_coins;
    return min_coins;
}

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> values(n);
    for(int i=0; i<n; i++) 
        cin >> values[i];

    vector<int> coins(x+1, -2);
    coins[0] = 0;
    cout << get_coins(x, coins, values);

    return 0;
}
