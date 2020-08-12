#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i < rowIndex + 1; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

int main() {
    int rowIndex = 3;
    Solution solution;
    auto res = solution.getRow(rowIndex);
    for (auto num : res) {
        std::cout << num << " ";
    }
    return 0;
}