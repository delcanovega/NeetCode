#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        size_t rows = grid.size();
        size_t cols = grid[0].size();

        vector<vector<bool>> visited;
        visited.assign(rows, vector<bool>(cols, false));

        int islands = 0;
        for (size_t row = 0; row < rows; row++) {
            for (size_t col = 0; col < cols; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    islands++;
                    dfs(grid, visited, row, col, islands);
                }
                visited[row][col] = true;
            }
        }
        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, size_t i, size_t j, int& islands) {
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() || visited[i][j] || grid[i][j] == '0') {
            return;
        }

        visited[i][j] = true;
        dfs(grid, visited, i - 1, j, islands);
        dfs(grid, visited, i, j - 1, islands);
        dfs(grid, visited, i + 1, j, islands);
        dfs(grid, visited, i, j + 1, islands);
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1','1','0','0','1'},
        {'1','1','0','0','1'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    assert(sol.numIslands(grid) == 4);

    return 0;
}