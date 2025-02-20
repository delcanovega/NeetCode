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
    int maxPathSum(TreeNode* root) {
        max_path = -1001;
        dfs(root);
        return max_path;
    }
private:
    int max_path;
    int dfs(TreeNode* node) {
        if (!node) {
            return -1001;
        }

        int left = dfs(node->left) + node->val;
        int right = dfs(node->right) + node->val;
        int combined = left + right - node->val;

        int max_at_node = node->val;
        max_at_node = max(max_at_node, left);
        max_at_node = max(max_at_node, right);

        max_path = max(max_path, max_at_node);
        max_path = max(max_path, combined);
        
        // combined cannot be propagated to the parent,
        // hence the different variables for max_path and max_at_node
        return max_at_node;
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

        if (i < values.size() && values[i] != -1001) {
            curr->left = new TreeNode(values[i]);
            q.push(curr->left);
        }
        i++;

        if (i < values.size() && values[i] != -1001) {
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

    vector<int> tree{-15,10,20,-1001,-1001,15,5,-5};
    TreeNode* root = create_binary_tree(tree);
    assert(sol.maxPathSum(root) == 40);

    delete_tree(root);

    tree = {1,2};
    root = create_binary_tree(tree);
    assert(sol.maxPathSum(root) == 3);

    delete_tree(root);  

    return 0;
}