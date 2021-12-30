#include <string>
#include <iostream>
#include <climits>

using namespace std;

int main() {
    string str;

    getline(cin, str);

    int curr_length = 0, best_length = 0;
    auto prev_char = str[0];
    for(auto c : str) {
        curr_length = c == prev_char ? curr_length + 1 : 1;
        if (curr_length > best_length) {
            best_length = curr_length;
        }
        prev_char = c;
    }

    cout << best_length;

    return 0;
}
