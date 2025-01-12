#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int largest = 0;
        int i = 0;
        int j = heights.size() - 1;
        while (i < j) {
            int size = (j - i) * min(heights[i], heights[j]);
            largest = max(largest, size);
            if (heights[i] > heights[j]) {
                j--;
            } else {
                i++;
            }
        }
        return largest;
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {1,7,2,5,4,7,3,6};
    assert(sol.maxArea(test_1) == 36);

    vector<int> test_2 = {2,2,2};
    assert(sol.maxArea(test_2) == 4);

    return 0;
}
