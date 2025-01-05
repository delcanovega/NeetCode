#include <cassert>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solutions;
        stack<char> current;  // using a string would be more efficient. But we are in the Stack category!
        backtrack(n, current, 0, 0, solutions);
        return solutions;
    }

private:
    void backtrack(int n, stack<char>& current, int opened, int closed, vector<string>& solutions) {
        if (opened == n && closed == n) {
            solutions.push_back(transform(current));
            return;
        }

        if (opened < n) {
            current.push('(');
            backtrack(n, current, opened + 1, closed, solutions);
            current.pop();
        }
        if (closed < opened) {
            current.push(')');
            backtrack(n, current, opened, closed + 1, solutions);
            current.pop();
        }
    }

    string transform(stack<char> copy_of_current) {
        string result;
        while (!copy_of_current.empty()) {
            result += copy_of_current.top();
            copy_of_current.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    Solution sol;

    vector<string> test_1_output = {"()"};
    assert(sol.generateParenthesis(1) == test_1_output);

    vector<string> test_2_output = {"((()))","(()())","(())()","()(())","()()()"};
    assert(sol.generateParenthesis(3) == test_2_output);

    return 0;
}
