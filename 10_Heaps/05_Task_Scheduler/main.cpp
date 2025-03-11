#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> occurrences;
        for (char task : tasks) {
            occurrences[task]++;
        }

        priority_queue<int> max_heap;
        for (pair<char, int> task : occurrences) {
            max_heap.push(task.second);
        }

        int cycles = 0;
        queue<pair<int, int>> cooldown;  // <remaining_occurrences, release_cycle>
        while (!max_heap.empty() || !cooldown.empty()) {
            if (!cooldown.empty() && cooldown.front().second == cycles) {
                max_heap.push(cooldown.front().first);
                cooldown.pop();
            }

            cycles++;

            if (!max_heap.empty()) {
                int remaining_occurrences = max_heap.top() - 1;
                max_heap.pop();
                if (remaining_occurrences > 0) {
                    cooldown.push({remaining_occurrences, cycles + n});
                }
            }
        }
        return cycles;
    }
};

int main() {
    Solution sol;

    vector<char> tasks { 'X','X','Y','Y' };
    assert(sol.leastInterval(tasks, 2) == 5);

    return 0;
}