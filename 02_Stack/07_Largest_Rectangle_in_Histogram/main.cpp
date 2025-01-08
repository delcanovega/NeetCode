#include <cassert>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        
        stack<pair<int, int>> previous_heights;
        for (size_t i = 0; i < heights.size(); i++) {
            int height = heights[i];
            int effective_idx = i;

            while (!previous_heights.empty() && height < previous_heights.top().first) {
                pair<int, int> top = previous_heights.top();
                int available_height = top.first;
                int from_idx = top.second;
                previous_heights.pop();

                int size = (i - from_idx) * available_height;
                largest = max(largest, size);
                effective_idx = from_idx;
            }
            previous_heights.push(make_pair(height, effective_idx));
        }
        while (!previous_heights.empty()) {
            pair<int, int> top = previous_heights.top();
            int available_height = top.first;
            int from_idx = top.second;
            previous_heights.pop();

            int size = (heights.size() - from_idx) * available_height;
            largest = max(largest, size);
        }
        
        return largest;
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {7,1,7,2,2,4};
    assert(sol.largestRectangleArea(test_1) == 8);

    vector<int> test_2 = {1,3,7};
    assert(sol.largestRectangleArea(test_2) == 7);

    return 0;
}
