#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        vector<int> out;
        for (int & i : A) {
            if (i % 2) {
                out.push_back(i);
            } else {
                out.insert(out.begin(), i);
            }
        }
        return out;
    }
};

int main() {
    vector<int> A = {3, 1, 2, 4};
    Solution solution;
    auto res = solution.sortArrayByParity(A);
    for (auto n : res) {
        std::cout << n << " ";
    }
}
