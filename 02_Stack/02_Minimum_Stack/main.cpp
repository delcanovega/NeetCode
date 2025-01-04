#include <cassert>
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        nums.push(val);
        int current_min = mins.empty() ? val : min(val, mins.top());
        mins.push(current_min);
    }
    
    void pop() {
        nums.pop();
        mins.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }

private:
    stack<int> nums;
    stack<int> mins; 

};

void test(vector<string>& operations, vector<int>& values, vector<string>& expected_output) {
    vector<string> output(operations.size(), "null");

    MinStack min_stack;

    size_t operation_idx = 0;
    size_t value_idx = 0;
    while (operation_idx < operations.size()) {
        string op = operations[operation_idx];
        if (op == "MinStack") {
            min_stack = MinStack();
        } else if (op == "push") {
            min_stack.push(values[value_idx++]);
        } else if (op == "pop") {
            min_stack.pop();
        } else if (op == "top") {
            output[operation_idx] = to_string(min_stack.top());
        } else if (op == "getMin") {
            output[operation_idx] = to_string(min_stack.getMin());
        }
        operation_idx++;
    }

    assert(output == expected_output);
}

int main() {
    vector<string> test_1_ops = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<int> test_1_vals = {1, 2, 0};
    vector<string> test_1_result = {"null", "null", "null", "null", "0", "null", "2", "1"};
    test(test_1_ops, test_1_vals, test_1_result);

    return 0;
}
