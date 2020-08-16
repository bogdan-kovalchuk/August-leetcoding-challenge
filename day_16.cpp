#include <iostream>
#include <vector>

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

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution solution;
    std::cout << solution.maxProfit(prices) << std::endl;
    return 0;
}

