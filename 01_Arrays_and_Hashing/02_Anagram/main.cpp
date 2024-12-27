#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_letters;
        for (char c: s) {
            s_letters[c]++;
        }
        unordered_map<char, int> t_letters;
        for (char c: t) {
            t_letters[c]++;
        }
        return s_letters == t_letters;
    }
};


int main() {
    Solution sol;

    assert(sol.isAnagram("racecar", "carrace") == true);

    assert(sol.isAnagram("jar", "jam") == false);

    return 0;
}
