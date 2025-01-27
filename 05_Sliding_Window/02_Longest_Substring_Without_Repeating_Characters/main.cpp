#include <cassert>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> active_chars;
        size_t longest = 0;
        size_t i = 0;
        size_t j = 0;
        while (j < s.length()) {
            if (active_chars.contains(s[j])) {
                while (i < j && active_chars.contains(s[j])) {
                    active_chars.erase(s[i]);
                    i++;
                }
            }
            active_chars.insert(s[j]);
            longest = max(longest, active_chars.size());
            j++;
        }
        return longest;
    }
};


int main() {
    Solution sol;

    assert(sol.lengthOfLongestSubstring("zxyzxyz") == 3);

    assert(sol.lengthOfLongestSubstring("xxxx") == 1);

    return 0;
}
