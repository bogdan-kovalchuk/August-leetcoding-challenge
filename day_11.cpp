#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        if (citations.empty()) return 0;
        int start = 0, end = citations.size() - 1;
        std::sort(citations.begin(), citations.end());
        while (start <= end) {
            int average = (end + start) / 2;
            if (citations[average] < citations.size() - average)
                start = average + 1;
            else
                end = average - 1;
        }
        return citations.size() - start;
    }
};

int main() {
    vector<int> citations = {11, 15};
    Solution solution;
    std::cout << solution.hIndex(citations) << std::endl;
    return 0;
}