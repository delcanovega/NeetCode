#include <cassert>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> rotting_cells;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    rotting_cells.push({row, col});
                }
            }
        }

        int cycles = 0;
        propagate_rot(grid, rotting_cells, rows, cols, cycles);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    return -1;
                }
            }
        }
        return cycles;
    }

private:
    void propagate_rot(vector<vector<int>>& grid, queue<pair<int, int>>& rotting_cells, int rows, int cols, int& cycles) {
        vector<pair<int, int>> directions{{-1,0}, {0,1}, {1,0}, {0,-1}};

        queue<pair<int, int>> next_cycle;
        while (!rotting_cells.empty()) {
            pair<int, int> cell = rotting_cells.front();
            rotting_cells.pop();

            for (int i = 0; i < 4; i++) {
                int row = cell.first + directions[i].first;
                int col = cell.second + directions[i].second;
                
                if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1) {
                    continue;
                }
                
                grid[row][col] = 2;
                next_cycle.push({row, col});
            }

            if (rotting_cells.empty() && !next_cycle.empty()) {
                cycles++;
                swap(rotting_cells, next_cycle);
                queue<pair<int,int>> empty;
                swap(next_cycle, empty);
            }
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 1, 0},
        {0, 1, 1},
        {0, 1, 2}
    };
    assert(sol.orangesRotting(grid) == 4);

    return 0;
}