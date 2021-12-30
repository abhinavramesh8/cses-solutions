#include <iostream>

using namespace std;

int main() {
    int a, b, t;

    cin >> t;
    while (t--) {
        cin >> a >> b;

        long x = a * 2L - b, y = b * 2L - a;
        cout << ((x >= 0 && y >= 0 && !(x%3) && !(y%3)) ? "YES" : "NO") << '\n';
    }

    return 0;
}
