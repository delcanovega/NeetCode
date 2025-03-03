#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        size_t rows = board.size();
        size_t cols = board[0].size();

        vector<vector<bool>> visited;
        visited.assign(rows, vector<bool>(cols, false));

        for (size_t row = 0; row < rows; row++) {
            for (size_t col = 0; col < cols; col++) {
                if (backtrack(board, word, "", row, col, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, string target, string current, size_t row, size_t col, vector<vector<bool>>& visited) {
        if (row < 0 || row >= board.size()
            || col < 0 || col >= board[0].size()
            || visited[row][col]
        ) {
            return false;
        }

        visited[row][col] = true;
        current.push_back(board[row][col]);
        
        if (current == target) {
            return true;
        } else if (!target.starts_with(current)) {
            current.pop_back();
            visited[row][col] = false;
            return false;
        } else {
            bool found = backtrack(board, target, current, row - 1, col, visited)
                || backtrack(board, target, current, row + 1, col, visited)
                || backtrack(board, target, current, row, col - 1, visited)
                || backtrack(board, target, current, row, col + 1, visited);

            current.pop_back();
            visited[row][col] = false;
            return found;
        }
    }
};
    

int main() {
    Solution sol;

    vector<vector<char>> board{
        {'A', 'B', 'C', 'D'},
        {'S', 'A', 'A', 'T'},
        {'A', 'C', 'A', 'E'}
    };
    assert(sol.exist(board, "CAT"));

    return 0;
}