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
    Solution orig;
    SolutionStateMachine sm;

    auto run = [&](vector<int> prices, const char *label) {
        int r1 = orig.maxProfit(prices);
        int r2 = sm.maxProfit(prices);
        std::cout << label << ": orig=" << r1 << " sm=" << r2
                  << (r1 == r2 ? " [match]" : " [MISMATCH]") << std::endl;
    };

    run({3, 3, 5, 0, 0, 3, 1, 4}, "basic");
    run({1, 2, 3, 4, 5}, "ascending");
    run({5, 4, 3, 2, 1}, "descending");
    run({}, "empty");
    run({1}, "single");
    run({1, 2}, "two_up");
    run({2, 1}, "two_down");
    run({1, 2, 4, 2, 5, 7, 2, 4, 9, 0}, "multi_peak");
    run({3, 3, 5, 0, 0, 3, 1, 4}, "leetcode_example");
    run({1, 2, 3, 2, 2}, "plateau");

    return 0;
}

