#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        return 0;
    }
};

int main() {
    vector<vector<int>> greed = {{2, 1, 1},
                                 {1, 1, 0},
                                 {0, 1, 1}};

    Solution solution;
    std::cout << solution.orangesRotting(greed) << std::endl;

    return 0;
}
