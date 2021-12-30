#include <iostream>

using namespace std;

int main() {
    int n;
    const int M = 1'000'000'007;

    cin >> n;

    int strings_num = 1;
    while (n--) {
        strings_num *= 2;
        strings_num %= M;
    }

    cout << strings_num;

    return 0;
}
