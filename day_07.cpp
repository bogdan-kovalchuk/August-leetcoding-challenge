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
    void dfs(TreeNode *r, int x, int y, map<int, map<int, set<int>>> &m) {
        if (r != nullptr) {
            m[x][y].insert(r->val);
            dfs(r->left, x - 1, y + 1, m);
            dfs(r->right, x + 1, y + 1, m);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> res;
        map<int, map<int, set<int>>> map;
        dfs(root, 0, 0, map);
        for (auto &itx : map) {
            res.emplace_back();
            for (auto &ity : itx.second) {
                res.back().insert(end(res.back()), begin(ity.second), end(ity.second));
            }
        }
        return res;
    }
};

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    auto res = solution.verticalTraversal(root);

    for (const auto& v: res){
        std::cout << "[ ";
        for (const auto &n: v) {
            std::cout << n << " ";
        }
        std::cout << "]";
    }

    return 0;
}


// --- Alternative: BFS with column tracking ---
// Time O(n log n) for final sort, Space O(n)
// Edge cases: level-order guarantees row ordering; values at same (col,row) sorted
// Compare: original uses nested map (auto-sorted but high constant factor);
// BFS collects then sorts - same result with potentially better cache behavior
#include <climits>
#include <tuple>
#include <queue>
class SolutionBFS {
    struct Cell { int col, row, val; };
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        if (!root) return {};
        vector<Cell> cells;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* node = front.first;
            int x = front.second.first, y = front.second.second;
            cells.push_back({x, y, node->val});
            if (node->left)  q.push({node->left,  {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }
        sort(cells.begin(), cells.end(), [](const Cell& a, const Cell& b) {
            if (a.col != b.col) return a.col < b.col;
            if (a.row != b.row) return a.row < b.row;
            return a.val < b.val;
        });
        vector<vector<int>> res;
        int prevCol = INT_MIN;
        for (auto& c : cells) {
            if (c.col != prevCol) { res.emplace_back(); prevCol = c.col; }
            res.back().push_back(c.val);
        }
        return res;
    }
};