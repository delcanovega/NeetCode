#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        backtrack(0, board, solutions);
        return solutions;
    }

private:
    void backtrack(size_t row, vector<string>& board, vector<vector<string>>& solutions) {
        if (row == board.size()) {
            solutions.push_back(board);
            return;
        }

        for (size_t col = 0; col < board.size(); col++) {
            if (valid(row, col, board)) {
                board[row][col] = 'Q';
                backtrack(row + 1, board, solutions);
                board[row][col] = '.';
            }
        }
    }

    bool valid(int row, int col, vector<string>& board) {
        // vertical
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < (int) board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
    

int main() {
    Solution sol;

    vector<vector<string>> expected{{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}};
    assert(sol.solveNQueens(4) == expected);

    return 0;
}