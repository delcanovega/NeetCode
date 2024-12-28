#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx_by_value;
        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (idx_by_value.contains(diff)) {
                return {idx_by_value[diff], (int) i};
            }
            idx_by_value[nums[i]] = i;
        }
        return {};
    }
};


int main() {
    Solution sol;

    vector<int> test_1{3, 4, 5, 6};
    vector<int> test_1_output{0, 1};
    assert(sol.twoSum(test_1, 7) == test_1_output);

    vector<int> test_2{4, 5, 6};
    vector<int> test_2_output{0, 2};
    assert(sol.twoSum(test_2, 10) == test_2_output);

    vector<int> test_3{5, 5};
    vector<int> test_3_output{0, 1};
    assert(sol.twoSum(test_3, 10) == test_3_output);

    return 0;
}
