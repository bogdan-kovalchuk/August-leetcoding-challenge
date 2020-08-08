#include <iostream>
#include <vector>
#include <set>
#include <map>

using std::vector;
using std::set;
using std::map;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return sum_up(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int sum_up(TreeNode *root, int prev_sum, const int &sum) {
        if (!root) return 0;
        int current_sum = prev_sum + root->val;
        return (current_sum == sum) +
               sum_up(root->left, current_sum, sum) +
               sum_up(root->right, current_sum, sum);
    }
};

int main() {
    int sum = 8;
    auto *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->right->right = new TreeNode(11);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    Solution solution;
    std::cout << solution.pathSum(root, sum) << std::endl;

    return 0;
}

