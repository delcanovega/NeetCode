#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (!digits.empty()) {
            backtrack(digits, 0, "", combinations);
        }
        return combinations;
    }

private:
    unordered_map<char, vector<char>> letters_by_number{
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    void backtrack(string digits, size_t i, string current, vector<string>& combinations) {
        if (current.size() == digits.size()) {
            combinations.push_back(current);
            return;
        }

        for (char letter : letters_by_number.at(digits[i])) {
            current.push_back(letter);
            backtrack(digits, i + 1, current, combinations);
            current.pop_back();
        }
    }
};
    

int main() {
    Solution sol;

    vector<string> expected{"dg","dh","di","eg","eh","ei","fg","fh","fi"};
    assert(sol.letterCombinations("34") == expected);

    return 0;
}