#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size() - 1);
    }

private:
    int binary_search(vector<int>& nums, int target, int from, int to) {
        if (from > to) {
            return -1;
        }

        int i = from + (to - from) / 2;
        if (nums[i] > target) {
            return binary_search(nums, target, from, i - 1);
        } else if (nums[i] < target) {
            return binary_search(nums, target, i + 1, to);
        } else {
            return i;
        }
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {-1,0,2,4,6,8};
    assert(sol.search(test_1, 4) == 3);

    vector<int> test_2 = {-1,0,2,4,6,8};
    assert(sol.search(test_2, 3) == -1);

    return 0;
}
