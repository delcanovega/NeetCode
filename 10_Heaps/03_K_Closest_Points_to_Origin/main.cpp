#include <cassert>
#include <queue>
#include <vector>
using namespace std;

struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        float dist_a = sqrt(pow(a[0], 2.0) + pow(a[1], 2.0));
        float dist_b = sqrt(pow(b[0], 2.0) + pow(b[1], 2.0));
        return dist_a < dist_b;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> max_heap;
        for (vector<int> point: points) {
            max_heap.push(point);
            if ((int) max_heap.size() > k) {
                max_heap.pop();
            }
        }

        vector<vector<int>> result;
        while (!max_heap.empty()) {
            result.push_back(max_heap.top());
            max_heap.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points { {0,2}, {2,0}, {2,2} };
    vector<vector<int>> closest { {2,0}, {0,2} };
    assert(sol.kClosest(points, 2) == closest);

    return 0;
}