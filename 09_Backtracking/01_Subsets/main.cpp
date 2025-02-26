#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> current_subset;
        backtrack(nums, 0, current_subset, subsets);
        return subsets;
    }

private:
    void backtrack(const vector<int>& nums, size_t i, vector<int>& current_subset, vector<vector<int>>& subsets) {
        if (i >= nums.size()) {
            subsets.push_back(current_subset);
            return;
        }

        // branch that includes the element
        current_subset.push_back(nums[i]);
        backtrack(nums, i + 1, current_subset, subsets);

        // branch that does not include the element
        current_subset.pop_back();
        backtrack(nums, i + 1, current_subset, subsets);
    }
};
    

int main() {
    Solution sol;

    vector<int> nums{1,2,3};
    vector<vector<int>> expected{
        {1,2,3},
        {1,2},
        {1,3},
        {1},
        {2,3},
        {2},
        {3},
        {}
    };
    assert(sol.subsets(nums) == expected);

    return 0;
}