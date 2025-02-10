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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }

private:
    int dfs(TreeNode* root, bool& balanced) {
        if (!root) {
            return 0;
        }

        int left_diameter = dfs(root->left, balanced);
        int right_diameter = dfs(root->right, balanced);
        balanced = balanced && abs(left_diameter - right_diameter) <= 1;
        return max(left_diameter, right_diameter) + 1;
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

    vector<int> input{1,2,3,-1,-1,4};
    TreeNode* root = create_binary_tree(input);

    assert(sol.isBalanced(root));

    delete_tree(root);

    input = {1,2,3,-1,-1,4,-1,5};
    root = create_binary_tree(input);

    assert(!sol.isBalanced(root));

    delete_tree(root);

    return 0;
}