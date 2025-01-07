#include <cassert>
#include <iostream>
#include <map>
#include <ranges>
#include <stack>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> speed_by_position;
        for (size_t i = 0; i < position.size(); i++) {
            speed_by_position[position[i]] = speed[i];
        }

        stack<float> time_to_goal;
        for (auto const& [pos, speed] : speed_by_position | views::reverse) {
            float remaining = target - pos;
            float time = remaining / speed;
            
            if (time_to_goal.empty() || time > time_to_goal.top()) {
                time_to_goal.push(time);
            } 
        } 
        return time_to_goal.size();
    }
};


int main() {
    Solution sol;

    vector<int> test_1_pos = {1,4};
    vector<int> test_1_speed = {3,2};
    assert(sol.carFleet(10, test_1_pos, test_1_speed) == 1);

    vector<int> test_2_pos = {4,1,0,7};
    vector<int> test_2_speed = {2,2,1,1};
    assert(sol.carFleet(10, test_2_pos, test_2_speed) == 3);

    return 0;
}
