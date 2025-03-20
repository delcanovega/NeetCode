#include <cassert>
#include <queue>
#include <vector>
using namespace std;

static int INF = 2147483647;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> cells;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    cells.push({row, col});
                }
            }
        }
        solve_map(grid, cells, rows, cols);
    }

private:
    void solve_map(vector<vector<int>>& grid, queue<pair<int, int>>& cells, int rows, int cols) {
        vector<pair<int, int>> directions{{-1,0}, {0,1}, {1,0}, {0,-1}};

        while (!cells.empty()) {
            pair<int, int> cell = cells.front();
            cells.pop();

            for (int i = 0; i < 4; i++) {
                int row = cell.first + directions[i].first;
                int col = cell.second + directions[i].second;
                
                if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != INF) {
                    continue;
                }
                
                grid[row][col] = grid[cell.first][cell.second] + 1;
                cells.push({row, col});
            }
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {INF,  -1,   0, INF},
        {INF, INF, INF,  -1},
        {INF,  -1, INF,  -1},
        {0,    -1, INF, INF}
    };
    vector<vector<int>> expected = {
        {3, -1, 0,  1},
        {2,  2, 1, -1},
        {1, -1, 2, -1},
        {0, -1, 3,  4}
    };
    sol.islandsAndTreasure(grid);
    assert(grid == expected);

    return 0;
}