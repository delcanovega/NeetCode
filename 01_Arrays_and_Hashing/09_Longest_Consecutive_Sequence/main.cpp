#include <cassert>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int longest = 0;

        for (int num: nums_set) {
            // Only process chains if we are the begining of one
            if (!nums_set.contains(num - 1)) {
                int length = 1;
                // Not quadratic since we only process chains once (from the beginning).
                // A fully sorted array would run this inner loop once and then only the outer,
                // resulting in O(2N) complexity => O(N) 
                while (nums_set.contains(num + length)) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }

};


int main() {
    Solution sol;

    vector<int> test_1{2,20,4,10,3,4,5};
    assert(sol.longestConsecutive(test_1) == 4);

    vector<int> test_2{0,3,2,5,4,6,1,1};
    assert(sol.longestConsecutive(test_2) == 7);
    
    return 0;
}
