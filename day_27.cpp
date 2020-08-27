#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        map<int, int> m;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            m[intervals[i][0]] = i;
        for (auto in : intervals) {
            auto itr = m.lower_bound(in[1]);
            if (itr == m.end()) {
                res.push_back(-1);
            } else {
                res.push_back(itr->second);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{3, 4},
                                     {2, 3},
                                     {1, 2}};
    Solution solution;
    auto res = solution.findRightInterval(intervals);
    for (auto r : res) {
        cout << r << " ";
    }
    return 0;
}