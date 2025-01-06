#include <cassert>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> unmatched_temps;

        for (size_t i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            // Compare with previous temps. We only need to compare with the top of the stack,
            // because if any of the previous ones would have been lower they would have already popped.
            while (!unmatched_temps.empty()) {
                pair<int, int> temp_and_idx = unmatched_temps.top();
                if (temp > temp_and_idx.first) {
                    result[temp_and_idx.second] = i - temp_and_idx.second;
                    unmatched_temps.pop();
                } else {
                    break;
                }
            }
            unmatched_temps.push(make_pair(temp, i));
        }

        return result;
    }
};


int main() {
    Solution sol;

    vector<int> test_1 = {30,38,30,36,35,40,28};
    vector<int> test_1_output = {1,4,1,2,1,0,0};
    assert(sol.dailyTemperatures(test_1) == test_1_output);

    vector<int> test_2 = {22,21,20};
    vector<int> test_2_output = {0,0,0};
    assert(sol.dailyTemperatures(test_2) == test_2_output);

    return 0;
}
