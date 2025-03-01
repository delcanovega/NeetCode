#include <cassert>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> current_permutation;
        unordered_set<int> visited;
        backtrack(nums, current_permutation, visited, permutations);
        return permutations;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& current_permutation, unordered_set<int>& visited, vector<vector<int>>& permutations) {
        if (current_permutation.size() == nums.size()) {
            permutations.push_back(current_permutation);
            return;
        }

        for (int num : nums) {
            if (!visited.count(num)) {
                visited.insert(num);
                current_permutation.push_back(num);
                backtrack(nums, current_permutation, visited, permutations);
                current_permutation.pop_back();
                visited.erase(num);
            }
        }
    }
};
    

int main() {
    Solution sol;

    vector<int> nums{1,2,3};
    vector<vector<int>> expected{
        {1,2,3},
        {1,3,2},
        {2,1,3},
        {2,3,1},
        {3,1,2},
        {3,2,1}
    };
    assert(sol.permute(nums) == expected);

    return 0;
}