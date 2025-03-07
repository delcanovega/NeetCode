#include <cassert>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        max_size = k;
        for (int num : nums) {
            min_heap.push(num);
            if (min_heap.size() > max_size) {
                min_heap.pop();
            }
        } 
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > max_size) {
            min_heap.pop();
        }
        return min_heap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    size_t max_size;
};

int main() {
    vector<int> nums{1, 2, 3, 3};
    KthLargest heap = KthLargest(3, nums);

    assert(heap.add(3) == 3);
    assert(heap.add(5) == 3);
    assert(heap.add(6) == 3);
    assert(heap.add(7) == 5);
    assert(heap.add(8) == 6);

    return 0;
}