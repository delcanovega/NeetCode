#include <cassert>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> open_parentheses;
        set<char> openings = {'(', '[', '{'};

        for (char parentheses : s) {
            if (openings.contains(parentheses)) {
                open_parentheses.push(parentheses);
            } else {
                char expected = matching_parentheses(parentheses);
                if (open_parentheses.empty() || open_parentheses.top() != expected) {
                    return false;
                } else {
                    open_parentheses.pop();
                }
            }
        }

        return open_parentheses.empty();
    }

private:
    char matching_parentheses(char closing) {
        switch (closing) {
            case '}':
                return '{';
            case ']':
                return '[';
            case ')':
                return '(';
            default:
                return 'x';
        }
    }
};


int main() {
    Solution sol;

    string test_1 = "[]";
    assert(sol.isValid(test_1) == true);

    string test_2 = "([{}])";
    assert(sol.isValid(test_2) == true);

    string test_3 = "[(])";
    assert(sol.isValid(test_3) == false);

    return 0;
}
