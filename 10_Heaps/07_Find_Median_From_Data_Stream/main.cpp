#include <cassert>
#include <queue>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        max_heap.push(num);
        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        // balance heaps
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() > min_heap.size()) {
            return (double) max_heap.top();
        } else if (min_heap.size() > max_heap.size()) {
            return (double) min_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }

private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

int main() {
    MedianFinder mf;

    mf.addNum(1);
    assert(mf.findMedian() == 1.0);
    mf.addNum(3);
    assert(mf.findMedian() == 2.0);
    mf.addNum(2);
    assert(mf.findMedian() == 2.0);

    return 0;
}