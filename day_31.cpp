
#include <iostream>

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
    TreeNode *findMin(TreeNode *node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            TreeNode *minNode = findMin(root->right);
            if (!minNode) {
                minNode = root->left;
                delete root;
                return minNode;
            }
            root->val = minNode->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};

int main() {
    int key = 7;
    auto root =  new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution solution;
    auto res = solution.deleteNode(root, key);
    return 0;
}

