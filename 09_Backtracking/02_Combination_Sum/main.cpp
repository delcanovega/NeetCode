#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> subsets;
        vector<int> current_subset;
        backtrack(nums, target, 0, 0, current_subset, subsets);
        return subsets;
    }

private:
    void backtrack(const vector<int>& nums, int target, size_t i, int current_sum, vector<int>& current_subset, vector<vector<int>>& solutions) {
        if (current_sum == target) {
            solutions.push_back(current_subset);
            return;
        }
        if (current_sum > target || i >= nums.size()) {
            return;
        }

        current_subset.push_back(nums[i]);
        backtrack(nums, target, i, current_sum + nums[i], current_subset, solutions);
        current_subset.pop_back();
        backtrack(nums, target, i + 1, current_sum, current_subset, solutions);
    }
};
    

int main() {
    Solution sol;

    vector<int> nums{3,4,5};
    vector<vector<int>> expected{
        {3,3,3,3,4},
        {3,3,5,5},
        {3,4,4,5},
        {4,4,4,4}
    };
    assert(sol.combinationSum(nums, 16) == expected);

    return 0;
}