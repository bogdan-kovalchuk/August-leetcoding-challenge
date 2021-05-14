#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    // End-sort greedy: O(n log n) time, O(1) extra space
    // Sort by end time; greedily keep earliest-ending intervals, count removals
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
class SolutionStartSort {
public:
    // Start-sort forward sweep: O(n log n) time, O(1) extra space
    // Sort by start; on overlap keep the shorter interval (min end), discard the other
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) return 0;
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int res = 0;
        int prev_end = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] < prev_end) {
                ++res;
                prev_end = std::min(prev_end, intervals[i][1]);
            } else {
                prev_end = intervals[i][1];
            }
        }
        return res;
    }
};

int main() {
    Solution orig;
    SolutionStartSort startSort;

    auto run = [&](vector<vector<int>> intervals, const char *label) {
        vector<vector<int>> c1 = intervals, c2 = intervals;
        int r1 = orig.eraseOverlapIntervals(c1);
        int r2 = startSort.eraseOverlapIntervals(c2);
        std::cout << label << ": orig=" << r1 << " startSort=" << r2
                  << (r1 == r2 ? " [match]" : " [MISMATCH]") << std::endl;
    };

    run({{1, 2}, {2, 3}, {3, 4}, {1, 3}}, "basic");
    run({{1, 2}, {1, 2}, {1, 2}}, "all_same");
    run({{1, 2}, {2, 3}}, "no_overlap");
    run({{1, 10}, {2, 3}, {3, 4}, {4, 5}}, "one_big");
    run({}, "empty");
    run({{1, 5}, {2, 6}, {3, 7}, {4, 8}}, "chain");

    return 0;
}

