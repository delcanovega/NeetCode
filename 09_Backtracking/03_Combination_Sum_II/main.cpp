#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> subsets;
        vector<int> current_subset;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, current_subset, subsets);
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
        backtrack(nums, target, i + 1, current_sum + nums[i], current_subset, solutions);
        current_subset.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(nums, target, i + 1, current_sum, current_subset, solutions);
    }
};
    

int main() {
    Solution sol;

    vector<int> nums{9,2,2,4,6,1,5};
    vector<vector<int>> expected{
        {1,2,5},
        {2,2,4},
        {2,6}
    };
    assert(sol.combinationSum2(nums, 8) == expected);

    return 0;
}