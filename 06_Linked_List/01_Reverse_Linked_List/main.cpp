#include <cassert>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }

    ListNode* reverseListRecursively(ListNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        ListNode* head = node;
        if (head->next) {
            head = reverseListRecursively(node->next);
            node->next->next = node;
            node->next = nullptr;
        }
        return head;
    }

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
};

int main() {
    Solution sol;
    vector<int> input{0,1,2,3};
    vector<int> reversed{3,2,1,0};
    ListNode* node = sol.create_linked_list(input);
    
    node = sol.reverseList(node);
    assert(sol.get_values(node) == reversed);

    node = sol.reverseListRecursively(node);
    assert(sol.get_values(node) == input);
    
    sol.delete_linked_list(node);

    return 0;
}