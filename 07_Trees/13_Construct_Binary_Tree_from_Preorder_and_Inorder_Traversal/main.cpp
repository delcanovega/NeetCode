#include <cassert>
#include <queue>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (size_t i = 0; i < inorder.size(); ++i) {
            inorder_idx_by_value[inorder[i]] = i;
        }
        i = 0;
        return buildTree(preorder, 0, preorder.size() - 1);
    }
private:
    unordered_map<int, size_t> inorder_idx_by_value;
    int i;

    TreeNode* buildTree(vector<int>& preorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[i]);
        size_t m = inorder_idx_by_value[preorder[i]];
        i++;
        node->left = buildTree(preorder, l, m - 1);
        node->right = buildTree(preorder, m + 1, r);
        return node;
    }
};

void delete_tree(TreeNode* root) {
    if (!root) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main() {
    Solution sol;

    vector<int> preorder{1,2,3,4};
    vector<int> inorder{2,1,3,4};
    TreeNode* root = sol.buildTree(preorder, inorder);

    delete_tree(root);

    return 0;
}