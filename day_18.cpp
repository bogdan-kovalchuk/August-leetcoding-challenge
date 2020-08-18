#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {

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