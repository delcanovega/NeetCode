#include <cassert>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap {less<int>(), stones};
        while (max_heap.size() > 1) {
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();
            if (x != y) {
                max_heap.push(abs(x - y));
            }
        }
        return max_heap.empty() ? 0 : max_heap.top();
    }
};

int main() {
    Solution sol;

    vector<int> stones{2,3,6,2,4};
    assert(sol.lastStoneWeight(stones) == 1);

    return 0;
}