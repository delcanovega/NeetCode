#include <cassert>
#include <queue>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
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

    vector<int> tree_1{1,2,3};
    TreeNode* root_1 = create_binary_tree(tree_1);
    TreeNode* root_2 = create_binary_tree(tree_1);

    assert(sol.isSameTree(root_1, root_2));

    delete_tree(root_1);
    delete_tree(root_2);

    vector<int> tree_2{4,7};
    vector<int> tree_3{4,-1,7};
    TreeNode* root_3 = create_binary_tree(tree_2);
    TreeNode* root_4 = create_binary_tree(tree_3);

    assert(!sol.isSameTree(root_3, root_4));

    delete_tree(root_3);
    delete_tree(root_4);

    return 0;
}