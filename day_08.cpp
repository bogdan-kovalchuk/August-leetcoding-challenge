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


// --- Alternative: prefix-sum + hash map during single DFS ---
// Time O(n), Space O(n) - vs O(n^2) brute force above
// Edge cases: handles negative node values; empty tree returns 0
// Compare: original restarts sum_up from every node - O(n^2) worst case;
// prefix-sum approach tracks running sum from root and counts matches
// in one pass using a frequency map of prefix sums seen so far
#include <unordered_map>
class SolutionPrefix {
    int count = 0;
    unordered_map<int,int> prefixFreq;
    void dfs(TreeNode* node, int runningSum, int target) {
        if (!node) return;
        runningSum += node->val;
        if (runningSum == target) ++count;
        auto it = prefixFreq.find(runningSum - target);
        if (it != prefixFreq.end()) count += it->second;
        ++prefixFreq[runningSum];
        dfs(node->left, runningSum, target);
        dfs(node->right, runningSum, target);
        --prefixFreq[runningSum];
    }
public:
    int pathSum(TreeNode* root, int sum) {
        count = 0;
        prefixFreq.clear();
        dfs(root, 0, sum);
        return count;
    }
};
// --- Alternative: iterative DFS with explicit stack and prefix map ---
// Time O(n), Space O(n) - avoids recursion depth limit
// Edge cases: must save/restore map state on backtrack - same prefix-sum logic
// Compare: recursive prefix-sum DFS is cleaner; iterative version uses
// explicit stack with backtrack markers to maintain prefix frequency map
class SolutionIterative {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int count = 0, runningSum = 0;
        unordered_map<int,int> freq;
        stack<pair<TreeNode*,int>> stk;
        stk.push({root, 0});
        while (!stk.empty()) {
            auto& top = stk.top();
            TreeNode* node = top.first;
            int phase = top.second;
            if (phase == 0) {
                runningSum += node->val;
                if (runningSum == sum) ++count;
                auto it = freq.find(runningSum - sum);
                if (it != freq.end()) count += it->second;
                ++freq[runningSum];
                top.second = 1;
                if (node->left) stk.push({node->left, 0});
            } else if (phase == 1) {
                top.second = 2;
                if (node->right) stk.push({node->right, 0});
            } else {
                --freq[runningSum];
                runningSum -= node->val;
                stk.pop();
            }
        }
        return count;
    }
};