#include <iostream>

using namespace std;

// Definition for a binary tree node.
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
    int sumOfLeftLeaves(TreeNode *root) {
        int sum = 0;
        bfs(root, sum, false);
        return sum;
    }

    void bfs(TreeNode *root, int &sum, bool left) {
        if (root == nullptr) return;
        if (left && !root->left && !root->right) {
            sum += root->val;
            return;
        }
        bfs(root->left, sum, true);
        bfs(root->right, sum, false);
    }
};

int main() {
    auto head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);

    Solution solution;
    std::cout << solution.sumOfLeftLeaves(head);

    return 0;
}