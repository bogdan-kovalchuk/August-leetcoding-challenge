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
// --- Alternative: swap-based cycle placement ---
// Time O(n), Space O(1) - each element swapped at most twice into place
// Edge cases: duplicates end up at wrong indices after all swaps complete
// Compare: original negates values to mark seen (mutates signs);
// cycle sort physically moves elements to correct index - same O(n) time
// but different mutation pattern; works even if sign bit is needed
class SolutionCycle {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> out;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1)
                out.push_back(nums[i]);
        return out;
    }
};