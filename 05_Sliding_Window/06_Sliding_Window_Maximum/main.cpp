#include <cassert>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, size_t k) {
        map<int, int> numbers;
        for (size_t i{0}; i < k; i++) {
            numbers[nums[i]]++;
        }
        auto it = numbers.crbegin();
        vector<int> result = {it->first};
        for (size_t i{k}; i < nums.size(); i++) {
            numbers[nums[i]]++;
            numbers[nums[i - k]]--;
            if (numbers[nums[i - k]] == 0) {
                numbers.erase(nums[i - k]);
            }
            it = numbers.crbegin();
            result.push_back(it->first);
        }
        return result;
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {1,2,1,0,4,2,6};
    vector<int> test_1_result = {2,2,4,4,6};
    assert(sol.maxSlidingWindow(test_1, 3) == test_1_result);

    return 0;
}
