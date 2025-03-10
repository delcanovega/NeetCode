#include <cassert>
#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int num: nums) {
            min_heap.push(num);
            if (min_heap.size() > (size_t) k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};

int main() {
    Solution sol;

    vector<int> nums { 2,3,1,1,5,5,4 };
    assert(sol.findKthLargest(nums, 3) == 4);

    return 0;
}