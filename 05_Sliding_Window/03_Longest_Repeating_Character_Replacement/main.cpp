#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> present_chars(s.begin(), s.end());

        size_t longest = 0;
        for (char c : present_chars) {
            queue<int> idx_of_replacements;
            size_t i = 0;
            size_t j = 0;
            while (j < s.length()) {
                if (s[j] != c) {
                    if ((int) idx_of_replacements.size() < k) {
                        idx_of_replacements.push(j);
                    } else if (k > 0) {
                        i = idx_of_replacements.front() + 1;
                        idx_of_replacements.pop();
                        idx_of_replacements.push(j);
                    } else {
                        i = j + 1;
                    }
                }
                longest = max(longest, j - i + 1);
                j++;
            }
        }
        return longest;
    }
};


int main() {
    Solution sol;

    assert(sol.characterReplacement("XYYX", 2) == 4);

    assert(sol.characterReplacement("AAABABB", 1) == 5);

    assert(sol.characterReplacement("AABABBA", 1) == 4);

    assert(sol.characterReplacement("AABA", 0) == 2);

    return 0;
}
