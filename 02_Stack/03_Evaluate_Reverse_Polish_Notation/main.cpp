#include <cassert>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (string token : tokens) {
            if (ops.contains(token)) {
                int op2 = pop_top(operands);
                int op1 = pop_top(operands);
                operands.push(ops[token](op1, op2));
            } else {
                operands.push(stoi(token));
            }
        }

        return operands.top();
    }
private:
    unordered_map<string, function<int(int, int)>> ops = {
        {"+", [](int x, int y) -> int { return x + y; }},
        {"-", [](int x, int y) -> int { return x - y; }},
        {"*", [](int x, int y) -> int { return x * y; }},
        {"/", [](int x, int y) -> int { return floor(x / y); }}
    };

    int pop_top(stack<int>& ops) {
        int top = ops.top();
        ops.pop();
        return top;
    }
};


int main() {
    Solution sol;

    vector<string> test_1 = {"1","2","+","3","*","4","-"};
    assert(sol.evalRPN(test_1) == 5);

    return 0;
}
