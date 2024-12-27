#include <cassert>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> seen;
        for(const int& num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};


int main() {
    Solution sol;

    vector<int> test_1{1, 2, 3, 3};
    assert(sol.hasDuplicate(test_1) == true);

    vector<int> test_2{1, 2, 3, 4};
    assert(sol.hasDuplicate(test_2) == false);

    return 0;
}
