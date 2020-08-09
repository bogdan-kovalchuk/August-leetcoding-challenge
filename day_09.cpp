#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

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
