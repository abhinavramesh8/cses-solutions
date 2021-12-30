#include <iostream>

using namespace std;

bool reserved[8][8];
bool cols[8];
bool left_diags[15];
bool right_diags[15];
size_t num_of_placements = 0;

void find_placements(size_t row_num) {
    if (row_num == 8) {
        num_of_placements++;
    }
    else {
        for (size_t col_num = 0; col_num < 8; col_num++) {
            size_t left_diag_num = 7 + row_num - col_num;
            size_t right_diag_num = row_num + col_num;
            if (!reserved[row_num][col_num] && !cols[col_num] && 
                !left_diags[left_diag_num] && !right_diags[right_diag_num]) {
                cols[col_num] = left_diags[left_diag_num] = 
                                right_diags[right_diag_num] = true;
                find_placements(row_num+1);
                cols[col_num] = left_diags[left_diag_num] = 
                                right_diags[right_diag_num] = false;
            }

        }
    }
}

int main() {
    string row;

    for (size_t row_num=0; getline(cin, row); row_num++) {
        for (size_t col_num=0; col_num<row.size(); col_num++) {
            reserved[row_num][col_num] = (row[col_num] == '*');
        }
    }

    find_placements(0);

    cout << num_of_placements;

    return 0;
}
