#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> letters;
        for (char c : s1) {
            letters[c]++;
        }

        for (size_t i = 0; i < s1.size(); i++) {
            letters[s2[i]]--;
            if (letters[s2[i]] == 0) {
                letters.erase(s2[i]);
            }
        }
        if (letters.empty()) {
            return true;
        }
        size_t l = 0;
        size_t r = s1.size();
        while (r < s2.size()) {
            letters[s2[l]]++;
            if (letters[s2[l]] == 0) {
                letters.erase(s2[l]);
            }
            l++;
            letters[s2[r]]--;
            if (letters[s2[r]] == 0) {
                letters.erase(s2[r]);
            }
            r++;
            if (letters.empty()) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    Solution sol;

    assert(sol.checkInclusion("abc", "lecabee"));
    assert(!sol.checkInclusion("abc", "lecaabee"));

    return 0;
}
