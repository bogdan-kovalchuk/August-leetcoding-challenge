#include <iostream>
#include <vector>
#include <climits>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> prices) {
        if (prices.empty()) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int k = 1; k <= 2; k++) {
            int min = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                min = std::min(min, prices[i] - dp[k - 1][i - 1]);
                dp[k][i] = std::max(dp[k][i - 1], prices[i] - min);
            }
        }
        return dp[2][prices.size() - 1];
    }
};

class SolutionStateMachine {
public:
    int maxProfit(vector<int> prices) {
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (int p : prices) {
            buy1 = std::max(buy1, -p);
            sell1 = std::max(sell1, buy1 + p);
            buy2 = std::max(buy2, sell1 - p);
            sell2 = std::max(sell2, buy2 + p);
        }
        return sell2;
    }
};

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution solution;
    std::cout << solution.maxProfit(prices) << std::endl;
    return 0;
}

