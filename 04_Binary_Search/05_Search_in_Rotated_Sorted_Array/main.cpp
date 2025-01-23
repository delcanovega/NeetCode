#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[l] <= nums[m]) {
                if (target < nums[l] || nums[m] < target) {
                    l = m + 1;                   
                } else {
                    r = m - 1;
                }
            } else {
                if (nums[m] > target || target > nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> test_1 = {3,4,5,6,1,2};
    assert(sol.search(test_1, 1) == 4);

    vector<int> test_2 = {3,5,6,0,1,2};
    assert(sol.search(test_2, 4) == -1);

    return 0;
}
