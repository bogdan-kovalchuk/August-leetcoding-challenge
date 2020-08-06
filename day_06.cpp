#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> out;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] >= 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            else
                out.emplace_back(abs(nums[i]));
        }
        return out;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    Solution solution;
    auto result = solution.findDuplicates(nums);

    for (auto n: result) {
        std::cout << n << " ";
    }
    return 0;
}