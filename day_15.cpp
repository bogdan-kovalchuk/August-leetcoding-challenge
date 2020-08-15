#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        return 0;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 2},
                                     {2, 3},
                                     {3, 4},
                                     {1, 3}};
    Solution solution;
    std::cout << solution.eraseOverlapIntervals(intervals) << std::endl;
    return 0;
}

