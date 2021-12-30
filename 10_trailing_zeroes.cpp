#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int factors, trailing_zeroes = 0;
    for (int curr_power = 5; (factors = n / curr_power) != 0; curr_power *= 5) {
        trailing_zeroes += factors;
    }

    cout << trailing_zeroes;
}
