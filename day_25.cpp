#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        unordered_set<int> d(days.begin(), days.end());
        vector<int> dp(366);
        for (int i = 1; i < 366; ++i) {
            if (d.find(i) == d.end()) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
            }
        }
        return dp[365];
    }
};

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};
    Solution solution;
    std::cout << solution.mincostTickets(days, costs);
    return 0;
}

