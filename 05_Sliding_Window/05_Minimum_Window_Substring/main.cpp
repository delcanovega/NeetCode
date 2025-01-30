#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target_letters;
        for (char c : t) {
            target_letters[c]++;
        }
        string result = "";

        unordered_map<char, int> current_letters;
        size_t l = 0;
        size_t r = 0;
        // grow the window until we have a valid solution
        while (r < s.size()) {
            char c = s[r];
            if (target_letters.contains(c)) {
                current_letters[c]++;
                // check if the letter that we just processed allows us to shrink the window from the left
                while (l < r && (!target_letters.contains(s[l]) || (current_letters[s[l]] > target_letters[s[l]]))) {
                    if (current_letters.contains(s[l])) {
                        current_letters[s[l]]--;
                    }
                    l++;
                }
                if (is_valid_solution(&current_letters, &target_letters)) {
                    size_t new_len = r - l + 1;
                    if (result.size() == 0 || result.size() > new_len) {
                        result = s.substr(l, new_len);
                    }
                }
            } else if (l == r) {
                l++;
            }
            r++;
        }
        return result;
    }
private:
    bool is_valid_solution(unordered_map<char, int>* current_letters, unordered_map<char, int>* target_letters) {
        for (pair<char, int> entry : *target_letters) {
            if ((*current_letters)[entry.first] < entry.second) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;

    assert(sol.minWindow("OUZODYXAZV", "XYZ") == "YXAZ");
    assert(sol.minWindow("xyz", "xyz") == "xyz");
    assert(sol.minWindow("xyz", "xtz") == "");
    assert(sol.minWindow("ADOBECODEBANC", "ABC") == "BANC");

    return 0;
}
