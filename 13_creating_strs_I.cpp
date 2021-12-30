#include <iostream>
#include <algorithm>

using namespace std;

constexpr size_t num_of_letters = 26;

// The function below is correct but doesn't generate strings in alphabetical
// order, which the question requires. Hence, I am commenting it out.
/* 
void generate_strings(string &s, int n, vector<bool>& chosen) {
    if (n == str_size) {
        cout << s << '\n';
    } 
    else {
        bool letters_presence[num_of_letters] = {false};
        for (int i = 0; i < str_size; i++) {
            auto c = str[i];
            if (!(letters_presence[c - 'a'] || chosen[i])) {
                letters_presence[c - 'a'] = true;
                chosen[i] = true;
                s[n] = c;
                generate_strings(s, n + 1, chosen);
                chosen[i] = false;
            }
        }
    }
}
*/

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    string str;
    cin >> str;

    int letter_counts[num_of_letters] = {0};
    for (auto c: str) {
        letter_counts[c - 'a']++;
    }
    int num_of_strings = factorial(str.size());
    for (auto i: letter_counts) {
        num_of_strings /= factorial(i);
    }

    cout << num_of_strings << '\n';
    
    sort(str.begin(), str.end());
    do {
        cout << str << '\n';
    } while (next_permutation(str.begin(), str.end()));
    
    return 0;
}
