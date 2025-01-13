#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {        
        vector<int> prefix_height(height.size(), 0);
        vector<int> sufix_height(height.size(), 0);
        calculate_pre_and_sufixes(height, prefix_height, sufix_height);

        int total = 0;
        for (size_t i = 1; i < height.size() - 1; i++) {
            int position_capacity = min(prefix_height[i-1], sufix_height[i+1]) - height[i];
            total += max(position_capacity, 0);
        }

        return total;
    }

private:
    void calculate_pre_and_sufixes(vector<int>& height, vector<int>& prefix_height, vector<int>& sufix_height) {
        int max_prefix = 0;
        int max_sufix = 0;
        for (size_t l = 0; l < height.size(); l++) {
            int r = height.size() - 1 - l;
            max_prefix = max(max_prefix, height[l]);
            max_sufix = max(max_sufix, height[r]);
            prefix_height[l] = max_prefix;
            sufix_height[r] = max_sufix;
        }
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {0,2,0,3,1,0,1,3,2,1};
    assert(sol.trap(test_1) == 9);

    return 0;
}
