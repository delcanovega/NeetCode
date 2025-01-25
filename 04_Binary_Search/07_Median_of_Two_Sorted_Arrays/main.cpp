#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* smaller_array = nullptr;
        vector<int>* bigger_array = nullptr;
        if (nums1.size() < nums2.size()) {
            smaller_array = &nums1;
            bigger_array = &nums2;
        } else {
            smaller_array = &nums2;
            bigger_array = &nums1;
        }

        int total_size = nums1.size() + nums2.size();
        int partition_size = total_size / 2;

        int l = 0;
        int r = smaller_array->size();
        while (l <= r) {
            size_t m = l + (r - l) / 2;
            size_t i = partition_size - m;

            int small_left = m > 0 ? smaller_array->at(m - 1) : INT_MIN;
            int small_right = m < smaller_array->size() ? smaller_array->at(m) : INT_MAX;
            int big_left = i > 0 ? bigger_array->at(i - 1) : INT_MIN;
            int big_right = i < bigger_array->size() ? bigger_array->at(i) : INT_MAX;

            if (small_left <= big_right && big_left <= small_right) {
                if (total_size % 2 == 1) {
                    return min(small_right, big_right);
                } else {
                    return (max(small_left, big_left) + min(small_right, big_right)) / 2.0;
                }
            } else if (small_left > big_right) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return - 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3};
    assert(sol.findMedianSortedArrays(nums1, nums2) == 2.0);

    nums1 = {1,3};
    nums2 = {2,4};
    assert(sol.findMedianSortedArrays(nums1, nums2) == 2.5);

    nums1 = {1,2};
    nums2 = {3,4};
    assert(sol.findMedianSortedArrays(nums1, nums2) == 2.5);

    return 0;
}
