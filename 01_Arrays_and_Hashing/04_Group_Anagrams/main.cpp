#include <cassert>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> groups_by_signature;
        for (string str: strs) {
            map<char, int> signature;
            for (char c: str) {
                signature[c]++;
            }

            groups_by_signature[signature].push_back(str);
        }
        vector<vector<string>> groups(from_range, views::values(groups_by_signature));
        return groups;
        /* if std < c++23:
        vector<vector<string>> values;
        for(auto it = groups_by_signature.begin(); it != groups_by_signature.end(); ++it) {
            values.push_back(it->second);
        }
        return values;
        */
    }
};


int main() {
    Solution sol;

    vector<string> test_1{"act","pots","tops","cat","stop","hat"};
    vector<vector<string>> test_1_output = sol.groupAnagrams(test_1);
    set<set<string>> test_1_solution{{"hat"},{"act", "cat"},{"stop", "pots", "tops"}};
    for (vector<string> group: test_1_output) {
        set<string> group_set(group.begin(), group.end());
        assert(test_1_solution.contains(group_set));
    }

    vector<string> test_2{"x"};
    vector<vector<string>> test_2_output = sol.groupAnagrams(test_2);
    set<set<string>> test_2_solution{{"x"}};
    for (vector<string> group: test_2_output) {
        set<string> group_set(group.begin(), group.end());
        assert(test_2_solution.contains(group_set));
    }

    vector<string> test_3{""};
    vector<vector<string>> test_3_output = sol.groupAnagrams(test_3);
    set<set<string>> test_3_solution{{""}};
    for (vector<string> group: test_3_output) {
        set<string> group_set(group.begin(), group.end());
        assert(test_3_solution.contains(group_set));
    }
    
    return 0;
}
