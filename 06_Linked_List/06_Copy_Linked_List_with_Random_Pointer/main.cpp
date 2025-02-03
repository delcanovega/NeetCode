#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> new_node_by_old_node;
        new_node_by_old_node[nullptr] = nullptr;

        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            new_node_by_old_node[current] = copy;
            current = current->next;
        }
        current = head;
        while (current) {
            new_node_by_old_node[current]->next = new_node_by_old_node[current->next];
            new_node_by_old_node[current]->random = new_node_by_old_node[current->random];
            current = current->next;
        }
        return new_node_by_old_node[head];
    }
};

Node* create_linked_list(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    Node* head = new Node(nums[0]);
    vector<Node*> nodes = {head};
    Node* current = head;

    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new Node(nums[i]);
        current = current->next;
        nodes.push_back(current);
    }
    nodes[1]->random = nodes[3];
    nodes[2]->random = nodes[0];
    nodes[3]->random = nodes[1];  

    return head;
}

void delete_linked_list(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    vector<int> input{1,2,3,4};
    Node* head = create_linked_list(input);    
    Node* head_copy = sol.copyRandomList(head);
    
    delete_linked_list(head);
    delete_linked_list(head_copy);

    return 0;
}