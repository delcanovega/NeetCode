#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (true) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {1,2,3,4};
    vector<int> test_1_result = {1, 2};
    assert(sol.twoSum(test_1, 3) == test_1_result);

    return 0;
}
