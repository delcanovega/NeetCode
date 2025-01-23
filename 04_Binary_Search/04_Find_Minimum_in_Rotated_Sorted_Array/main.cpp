#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 1;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m-1]) {
                return nums[m];
            } else if (min(nums[l], nums[m]) > nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[0];
    }
};

int main() {
    Solution sol;

    vector<int> test_1 = {3,4,5,6,1,2};
    assert(sol.findMin(test_1) == 1);

    vector<int> test_2 = {4,5,0,1,2,3};
    assert(sol.findMin(test_2) == 0);

    vector<int> test_3 = {4,5,6,7,0,1,2};
    assert(sol.findMin(test_3) == 0);

    return 0;
}
