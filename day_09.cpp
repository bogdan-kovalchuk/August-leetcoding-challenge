#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using std::vector;
using std::queue;
using std::stack;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dir = {{0,  1},
                                   {0,  -1},
                                   {1,  0},
                                   {-1, 0}};
        int fresh = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        if (fresh == 0) return 0;
        int res = -1;
        while (!q.empty()) {
            ++res;
            int qs = q.size();
            for (int i = 0; i < qs; ++i) {
                auto r = q.front();
                q.pop();
                for (auto d : dir) {
                    int x = r[0] + d[0];
                    int y = r[1] + d[1];

                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    fresh--;
                }
            }
        }
        return (fresh == 0) ? res : -1;
    }
};

class SolutionDFS {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 10000));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    dist[i][j] = 0;
                    stack<vector<int>> stk;
                    stk.push({i, j});
                    while (!stk.empty()) {
                        auto curr = stk.top();
                        stk.pop();
                        for (auto d : dir) {
                            int x = curr[0] + d[0];
                            int y = curr[1] + d[1];
                            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                                if (dist[curr[0]][curr[1]] + 1 < dist[x][y]) {
                                    dist[x][y] = dist[curr[0]][curr[1]] + 1;
                                    stk.push({x, y});
                                }
                            }
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    if (dist[i][j] == 10000) return -1;
                    res = std::max(res, dist[i][j]);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid1 = {{2, 1, 1},
                                 {1, 1, 0},
                                 {0, 1, 1}};

    vector<vector<int>> grid2 = {{2, 1, 1},
                                 {0, 1, 1},
                                 {1, 0, 1}};

    vector<vector<int>> grid3 = {{0, 2}};

    vector<vector<int>> grid4 = {{1},
                                 {2},
                                 {1},
                                 {2}};

    Solution solution;
    std::cout << solution.orangesRotting(grid1) << std::endl;
    std::cout << solution.orangesRotting(grid2) << std::endl;
    std::cout << solution.orangesRotting(grid3) << std::endl;
    std::cout << solution.orangesRotting(grid4) << std::endl;

    return 0;
}
