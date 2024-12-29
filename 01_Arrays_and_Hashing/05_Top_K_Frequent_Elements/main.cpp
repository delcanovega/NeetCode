#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, size_t k) {
        unordered_map<int, int> ocurrences_by_num;
        for (int num: nums) {
            ocurrences_by_num[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto& entry : ocurrences_by_num) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> top_k;
        for (size_t i = 0; i < k; ++i) {
            top_k.push_back(heap.top().second);
            heap.pop();
        }
        return top_k;
    }

};


int main() {
    Solution sol;

    vector<int> test_1{1,2,2,3,3,3};
    vector<int> test_1_solution{2,3};
    vector<int> test_1_output = sol.topKFrequent(test_1, 2);
    sort(test_1_output.begin(), test_1_output.end());
    assert(test_1_output == test_1_solution);

    vector<int> test_2{7,7};
    vector<int> test_2_solution{7};
    vector<int> test_2_output = sol.topKFrequent(test_2, 1);
    sort(test_2_output.begin(), test_2_output.end());
    assert(test_2_output == test_2_solution);
    
    return 0;
}
