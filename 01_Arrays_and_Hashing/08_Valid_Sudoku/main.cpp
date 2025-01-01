#include <cassert>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> nums_by_row;
        unordered_map<int, set<char>> nums_by_col;
        unordered_map<int, set<char>> nums_by_parcel;
        for(int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char cell = board[row][col];
                if (cell == '.') {
                    continue;
                }

                int parcel = determine_parcel(row, col);
                if (nums_by_col[col].contains(cell)
                        || nums_by_row[row].contains(cell)
                        || nums_by_parcel[parcel].contains(cell)) {
                    return false;
                } else {
                    nums_by_col[col].insert(cell);
                    nums_by_row[row].insert(cell);
                    nums_by_parcel[parcel].insert(cell);
                }
            }
        }
        return true;
    }

private:

    /*
    0 | 1 | 2
    - + - + -
    3 | 4 | 5
    - + - + -
    6 | 7 | 8
    */
    int determine_parcel(int row, int col) {
        return (row / 3) * 3 + (col / 3);
    }
};


int main() {
    Solution sol;

    vector<vector<char>> test_1{{'1','2','.','.','3','.','.','.','.'},
                                {'4','.','.','5','.','.','.','.','.'},
                                {'.','9','8','.','.','.','.','.','3'},
                                {'5','.','.','.','6','.','.','.','4'},
                                {'.','.','.','8','.','3','.','.','5'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','.','.','.','.','.','2','.','.'},
                                {'.','.','.','4','1','9','.','.','8'},
                                {'.','.','.','.','8','.','.','7','9'}};
    assert(sol.isValidSudoku(test_1) == true);

    vector<vector<char>> test_2{{'1','2','.','.','3','.','.','.','.'},
                                {'4','.','.','5','.','.','.','.','.'},
                                {'.','9','1','.','.','.','.','.','3'},
                                {'5','.','.','.','6','.','.','.','4'},
                                {'.','.','.','8','.','3','.','.','5'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','.','.','.','.','.','2','.','.'},
                                {'.','.','.','4','1','9','.','.','8'},
                                {'.','.','.','.','8','.','.','7','9'}};
    assert(sol.isValidSudoku(test_2) == false);
    
    return 0;
}
