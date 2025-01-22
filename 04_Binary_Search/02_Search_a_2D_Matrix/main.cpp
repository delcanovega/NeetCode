#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binary_search(matrix, target) != -1;
    }

private:
    int binary_search(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int r = rows * cols - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int row = m / cols;
            int col = m % cols;
            if (matrix[row][col] < target) {
                l = m + 1;
            } else if (matrix[row][col] > target) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};


int main() {
    Solution sol;

    vector<vector<int>> test_1 = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    assert(sol.searchMatrix(test_1, 10));

    vector<vector<int>> test_2 = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    assert(!sol.searchMatrix(test_2, 15));

    return 0;
}
