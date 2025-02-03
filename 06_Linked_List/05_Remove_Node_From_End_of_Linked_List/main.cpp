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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* probe = head;
        for (int i = 0; i < n; i++) {
            probe = probe->next;
        }

        ListNode* previous = nullptr;
        ListNode* nth = head;
        while (probe) {
            probe = probe->next;
            previous = nth;
            nth = nth->next;
        }

        if (previous) {
            previous->next = nth->next;
        } else {
            head = nth->next;
        }
        delete nth;
        return head;
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

    vector<int> input{1,2,3,4};
    vector<int> expected{1,2,4};
    ListNode* head = create_linked_list(input);
    
    head = sol.removeNthFromEnd(head, 2);
    assert(get_values(head) == expected);
    
    delete_linked_list(head);

    return 0;
}