#include <cassert>
#include <queue>
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

struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);

        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> mins;
        for (ListNode* head : lists) {
            mins.push(head);
        } 

        ListNode* current = dummy;
        while(!mins.empty()) {
            ListNode* min = mins.top();
            mins.pop();
            if (min->next) {
                mins.push(min->next);
            }
            current->next = min;
            current = current->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
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
    vector<int> list_3{3,6};
    vector<int> expected{1,1,2,3,3,4,5,6};
    ListNode* head_1 = create_linked_list(list_1);
    ListNode* head_2 = create_linked_list(list_2);
    ListNode* head_3 = create_linked_list(list_3);
    vector<ListNode*> input = {head_1, head_2, head_3};
    ListNode* result = sol.mergeKLists(input);
    assert(get_values(result) == expected);
    
    delete_linked_list(result);

    return 0;
}