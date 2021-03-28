#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    // Binary search after sort: O(n log n) time, O(1) extra space
    // Sorts in-place then binary searches for the partition point
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

class SolutionCounting {
public:
    // Counting sort: O(n) time, O(n) space for bucket array
    // Avoids comparison-based sort; caps citations at n since h <= n always
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for (int c : citations) {
            buckets[std::min(c, n)]++;
        }
        int cumulative = 0;
        for (int i = n; i >= 0; --i) {
            cumulative += buckets[i];
            if (cumulative >= i) return i;
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> tests = {{11, 15}, {3, 0, 6, 1, 5}, {1, 3, 1}, {0}, {100}};
    Solution orig;
    SolutionCounting counting;
    const char *labels[] = {"test1", "test2", "test3", "test4_single_zero", "test5_single_high"};
    for (int t = 0; t < (int)tests.size(); ++t) {
        vector<int> c1 = tests[t], c2 = tests[t];
        int r1 = orig.hIndex(c1);
        int r2 = counting.hIndex(c2);
        std::cout << labels[t] << ": orig=" << r1 << " counting=" << r2
                  << (r1 == r2 ? " [match]" : " [MISMATCH]") << std::endl;
    }
    return 0;
}