#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solutions;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;  // no more possible solutions (due to sorting)
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // ignore duplicates
            };

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    solutions.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;  // ignore duplicates
                    }
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return solutions;
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {-1,0,1,2,-1,-4};
    vector<vector<int>> test_1_result = {{-1,-1,2}, {-1,0,1}};
    assert(sol.threeSum(test_1) == test_1_result);

    vector<int> test_2 = {0,1,1};
    vector<vector<int>> test_2_result = {};
    assert(sol.threeSum(test_2) == test_2_result);

    return 0;
}
