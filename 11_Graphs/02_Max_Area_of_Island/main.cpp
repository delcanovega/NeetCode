#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        size_t rows = grid.size();
        size_t cols = grid[0].size();

        vector<vector<bool>> visited;
        visited.assign(rows, vector<bool>(cols, false));

        int largest = 0;
        for (size_t row = 0; row < rows; row++) {
            for (size_t col = 0; col < cols; col++) {
                if (!visited[row][col] && grid[row][col] == 1) {
                    int area = 0;
                    dfs(grid, visited, row, col, area);
                    largest = max(largest, area);
                }
                visited[row][col] = true;
            }
        }
        return largest;
    }

private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, size_t i, size_t j, int& area) {
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() || visited[i][j] || grid[i][j] == 0) {
            return;
        }

        area++;
        visited[i][j] = true;
        dfs(grid, visited, i - 1, j, area);
        dfs(grid, visited, i, j - 1, area);
        dfs(grid, visited, i + 1, j, area);
        dfs(grid, visited, i, j + 1, area);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0,1,1,0,1},
        {1,0,1,0,1},
        {0,1,1,0,1},
        {0,1,0,0,1}
    };
    assert(sol.maxAreaOfIsland(grid) == 6);

    return 0;
}