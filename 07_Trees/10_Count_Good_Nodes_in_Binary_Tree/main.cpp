#include <cassert>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;
        stack<int> max_in_branch;
        max_in_branch.push(-101); 
        dfs(root, good_nodes, max_in_branch);
        return good_nodes;
    }
private:
    void dfs(TreeNode* node, int& good_nodes, stack<int>& max_in_branch) {
        if (!node) {
            return;
        }

        if (node->val >= max_in_branch.top()) {
            good_nodes++;
            max_in_branch.push(node->val);
        } else {
            max_in_branch.push(max_in_branch.top());
        }
        dfs(node->left, good_nodes, max_in_branch);
        dfs(node->right, good_nodes, max_in_branch);
        max_in_branch.pop();
    }
};

TreeNode* create_binary_tree(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1) {
            curr->left = new TreeNode(values[i]);
            q.push(curr->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            curr->right = new TreeNode(values[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void delete_tree(TreeNode* root) {
    if (!root) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

vector<int> level_order_traversal(TreeNode* root) {
    vector<int> result;
    if (!root) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }

    return result;
}

int main() {
    Solution sol;

    vector<int> tree{2,1,1,3,-1,1,5};
    TreeNode* root = create_binary_tree(tree);
    assert(sol.goodNodes(root) == 3);

    delete_tree(root);

    return 0;
}