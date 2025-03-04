#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> solutions;
        vector<string> partition;
        backtrack(s, 0, partition, solutions);
        return solutions;
    }


private:
    void backtrack(string s, size_t i, vector<string>& partition, vector<vector<string>>& solutions) {
        if (i == s.size()) {
            solutions.push_back(partition);
            return;
        }

        for (size_t j = i; j < s.length(); j++) {
            string sub_s = s.substr(i, j - i + 1);
            string reversed = sub_s;
            reverse(reversed.begin(), reversed.end());
            if (reversed == sub_s) {
                partition.push_back(sub_s);
                backtrack(s, j + 1, partition, solutions);
                partition.pop_back();
            }
        }
    }
};
    

int main() {
    Solution sol;

    vector<vector<string>> expected{
        {"a", "a", "b"},
        {"aa", "b"}
    };
    assert(sol.partition("aab") == expected);

    return 0;
}