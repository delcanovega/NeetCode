#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> current_subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, current_subset, subsets);
        return subsets;
    }

private:
    void backtrack(const vector<int>& nums, size_t i, vector<int>& current_subset, vector<vector<int>>& solutions) {
        if (i >= nums.size()) {
            solutions.push_back(current_subset);
            return;
        }

        current_subset.push_back(nums[i]);
        backtrack(nums, i + 1, current_subset, solutions);
        current_subset.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(nums, i + 1, current_subset, solutions);
    }
};
    

int main() {
    Solution sol;

    vector<int> nums{1,2,2,3};
    vector<vector<int>> expected{
        {1,2,2,3},
        {1,2,2},
        {1,2,3},
        {1,2},
        {1,3},
        {1},
        {2,2,3},
        {2,2},
        {2,3},
        {2},
        {3},
        {}
    };
    assert(sol.subsetsWithDup(nums) == expected);

    return 0;
}