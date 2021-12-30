#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str;

    cin >> str;
    
    constexpr size_t num_of_chars = 256;
    int char_counts[num_of_chars] = {0};
    int num_of_odd_chars = 0;
    const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (auto c: str) {
        if ((++char_counts[c]) % 2) {
            num_of_odd_chars++;
        }
        else {
            num_of_odd_chars--;
        }
    }

    if (num_of_odd_chars > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    string odd_char, palindrome_half;
    for (auto c: letters) {
        string first_half_letters(char_counts[c]/2, c);
        palindrome_half += first_half_letters;
        if (char_counts[c] % 2) {
            odd_char += c;
        }
    }
    cout << palindrome_half << odd_char;
    reverse(palindrome_half.begin(), palindrome_half.end());
    cout << palindrome_half;
}
