#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    auto n_mod_four = n % 4;
    if (n_mod_four == 0) {
        cout << "YES\n" << n/2 << '\n';
        for (int i=1, j=n; i<=n/2; i+=2, j-=2) {
            cout << i << ' ' << j << ' ';
        }
        cout << '\n' << n/2 << '\n';
        for (int i=2, j=n-1; i<=n/2; i+=2, j-=2) {
            cout << i << ' ' << j << ' ';
        }
    }
    else if (n_mod_four == 3) {
        cout << "YES\n" << (n-3)/2 + 1 << "\n3 ";
        for (int i=4, j=n; i<=(n+4)/2; i+=2, j-=2) {
            cout << i << ' ' << j << ' ';
        }
        cout << '\n' << (n-3)/2 + 2 << "\n1 2 ";
        for (int i=5, j=n-1; i<=(n+4)/2; i+=2, j-=2) {
            cout << i << ' ' << j << ' ';
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}
