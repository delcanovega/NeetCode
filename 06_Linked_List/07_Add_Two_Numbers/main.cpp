#include <cassert>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0;
        int num2 = 0;
        int shift = 1;
        while(l1 || l2) {
            if (l1) {
                num1 += shift * l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num2 += shift * l2->val;
                l2 = l2->next;
            }
            shift *= 10;
        }

        string result = to_string(num1 + num2);
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        for (auto it = result.rbegin(); it != result.rend(); it++) {
            current->next = new ListNode(*it - '0');
            current = current->next;
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

ListNode* create_linked_list(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

void delete_linked_list(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

vector<int> get_values(ListNode* head) {
    vector<int> values;

    ListNode* node = head;
    while (node) {
        values.push_back(node->val);
        node = node->next;
    }

    return values;
}

int main() {
    Solution sol;

    vector<int> list_1{1,2,3};
    vector<int> list_2{4,5,6};
    vector<int> expected{5,7,9};
    ListNode* head_1 = create_linked_list(list_1);
    ListNode* head_2 = create_linked_list(list_2);
    
    ListNode* result = sol.addTwoNumbers(head_1, head_2);
    assert(get_values(result) == expected);
    
    delete_linked_list(head_1);
    delete_linked_list(head_2);
    delete_linked_list(result);

    return 0;
}