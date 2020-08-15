#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) return 0;
        int res = 0;
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int prev_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev_end) {
                ++res;
            }
            else {
                prev_end = intervals[i][1];
            }
        }
        return res;
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

