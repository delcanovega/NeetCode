#include <cassert>
#include <vector>
#include <stack>
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
    void reorderList(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        // find middle: slow = [1,2] -> 1. [1,2,3] -> 2. [1,2,3,4] -> 2. [1,2,3,4,5] -> 3.
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // alternative to stack: reverse second half for O(1) space
        stack<ListNode*> second_half;
        slow = slow->next;
        while (slow) {
            second_half.push(slow);
            slow = slow->next;
        }

        ListNode* current = head;
        ListNode* next = nullptr;
        while (!second_half.empty()) {
            next = current->next;
            current->next = second_half.top();
            second_half.pop();
            current->next->next = next;
            current = current->next->next;
        }
        current->next = nullptr;
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

    vector<int> list{0, 1, 2, 3, 4, 5, 6};
    ListNode* head = create_linked_list(list);
    
    sol.reorderList(head);
    vector<int> expected{0,6,1,5,2,4,3};
    assert(get_values(head) == expected);
    
    delete_linked_list(head);

    return 0;
}