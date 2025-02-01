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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) { return list2; }
        if (list2 == nullptr) { return list1; }

        ListNode* head = nullptr;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* current = head;
        while (list1 || list2) {
            if (list1 == nullptr) {
                current->next = list2;
                return head;
            } else if (list2 == nullptr) {
                current->next = list1;
                return head;
            } else if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
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

    vector<int> list_1{1,2,4};
    vector<int> list_2{1,3,5};
    ListNode* head_1 = create_linked_list(list_1);
    ListNode* head_2 = create_linked_list(list_2);
    
    ListNode* merged = sol.mergeTwoLists(head_1, head_2);
    vector<int> expected{1,1,2,3,4,5};
    assert(get_values(merged) == expected);
    
    delete_linked_list(merged);

    return 0;
}