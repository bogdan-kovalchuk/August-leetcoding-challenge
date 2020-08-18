#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        for (int i = 1; i < N; ++i) {
            vector<int> tmp;
            for (auto num: res) {
                auto last = num % 10;
                if (num > 0 && last + K < 10) {
                    tmp.push_back(10 * num + last + K);
                }
                if (num > 0 && K > 0 && last - K >= 0) {
                    tmp.push_back(10 * num + last - K);
                }
            }
            res = tmp;
        }
        return res;
    }
};

int main() {
    int N = 3, K = 7;
    Solution solution;
    auto res = solution.numsSameConsecDiff(N, K);
    for (auto r : res) {
        std::cout << r << " ";
    }
    return 0;
}