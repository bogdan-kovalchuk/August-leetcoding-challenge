#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {

    }
};

int main() {
    vector<int> A = {3, 1, 2, 4};
    Solution solution;
    auto res = solution.sortArrayByParity(A);
    for(auto n : res) {
        std::cout << n << " ";
    }
}
