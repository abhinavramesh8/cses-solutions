#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;

    cin >> n;
    vector<bool> appearances(n + 1, false);
    for (int i = 1; i < n; i++) {
        cin >> x;
        appearances[x] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!appearances[i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
