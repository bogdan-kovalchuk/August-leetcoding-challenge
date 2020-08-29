#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int> &A) {
        vector<int> out;
        int j, i;
        for (j = A.size(); j > 0; --j) {
            for (i = 0; A[i] != j; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            out.push_back(i + 1);
            reverse(A.begin(), A.begin() + j);
            out.push_back(j);
        }
        return out;
    }
};

int main() {
    vector<int> A = {3, 2, 4, 1};
    Solution solution;
    auto res = solution.pancakeSort(A);
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}