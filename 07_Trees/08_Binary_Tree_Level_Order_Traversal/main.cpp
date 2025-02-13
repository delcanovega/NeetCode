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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (!root) {
            return levels;
        }

        vector<TreeNode*> current_level{root};
        vector<TreeNode*> next_level;
        while(true) {
            vector<int> values;
            for (TreeNode* node : current_level) {
                values.push_back(node->val);
                if (node->left) {
                    next_level.push_back(node->left);
                }
                if (node->right) {
                    next_level.push_back(node->right);
                }
            }
            levels.push_back(values);
            if (next_level.empty()) {
                break;
            } else {
                current_level = next_level;
                next_level.clear();
            }
        }

        return levels;
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

    vector<int> tree{1,2,3,4,5,6,7};
    TreeNode* root = create_binary_tree(tree);
    vector<vector<int>> expected{{1},{2,3},{4,5,6,7}};
    assert(sol.levelOrder(root) == expected);

    delete_tree(root);

    return 0;
}