#include <iostream>

using namespace std;

int main() {
    size_t t;
    long long y, x;

    cin >> t;

    while (t--) {
        cin >> y >> x;

        if (x <= y) {
            auto y_odd = y % 2;
            auto y_start = y - y_odd;
            y_start = y_start*y_start + y_odd;
            cout << y_start + (2 * y_odd - 1) * (x - 1);
        }
        else {
            auto x_even = 1 - x % 2;
            auto x_start = x - x_even;
            x_start = x_start*x_start + x_even;
            cout << x_start + (2 * x_even - 1) * (y - 1);
        }
        cout << '\n';
    }
}
