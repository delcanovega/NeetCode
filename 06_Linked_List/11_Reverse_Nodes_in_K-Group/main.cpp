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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* tail_of_previous_k = dummy;

        while (true) {
            ListNode* head_of_k = get_head_of_k(tail_of_previous_k, k);
            ListNode* tail_of_k = tail_of_previous_k->next;
            if (!head_of_k) {
                break;
            }

            ListNode* previous = nullptr;
            ListNode* current = tail_of_previous_k->next;
            for (int i = 0; i < k; i++) {
                ListNode* next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            tail_of_previous_k->next = head_of_k;
            tail_of_k->next = current;
            tail_of_previous_k = tail_of_k;
        }

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }

private:
    ListNode* get_head_of_k(ListNode* current, int k) {
        int i = 0;
        while (current && i < k) {
            current = current->next;
            i++;
        }
        return current;
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

    vector<int> list{1,2,3,4,5,6};
    vector<int> expected{3,2,1,6,5,4};
    ListNode* head = create_linked_list(list);
    ListNode* result = sol.reverseKGroup(head, 3);
    assert(get_values(result) == expected);
    delete_linked_list(result);

    list = {1,2,3,4,5};
    expected = {3,2,1,4,5};
    head = create_linked_list(list);
    result = sol.reverseKGroup(head, 3);
    assert(get_values(result) == expected);
    delete_linked_list(result);

    return 0;
}