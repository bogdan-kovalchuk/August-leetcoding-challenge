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

class SolutionFormula {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int k = 1; k <= rowIndex; ++k) {
            res[k] = (long long)res[k - 1] * (rowIndex - k + 1) / k;
        }
        return res;
    }
};

int main() {
    Solution orig;
    SolutionFormula formula;
    int test_rows[] = {0, 1, 2, 3, 5, 10};
    const char *labels[] = {"row0", "row1", "row2", "row3", "row5", "row10"};

    for (int t = 0; t < 6; ++t) {
        auto r1 = orig.getRow(test_rows[t]);
        auto r2 = formula.getRow(test_rows[t]);
        std::cout << labels[t] << ": orig=[";
        for (int i = 0; i < (int)r1.size(); ++i) std::cout << r1[i] << (i + 1 < (int)r1.size() ? "," : "");
        std::cout << "] formula=[";
        for (int i = 0; i < (int)r2.size(); ++i) std::cout << r2[i] << (i + 1 < (int)r2.size() ? "," : "");
        std::cout << "]" << (r1 == r2 ? " [match]" : " [MISMATCH]") << std::endl;
    }

    int edge_rows[] = {15, 20, 30};
    const char *edge_labels[] = {"row15", "row20", "row30"};
    for (int t = 0; t < 3; ++t) {
        auto r1 = orig.getRow(edge_rows[t]);
        auto r2 = formula.getRow(edge_rows[t]);
        bool match = (r1 == r2);
        std::cout << edge_labels[t] << ": size=" << r1.size()
                  << (match ? " [match]" : " [MISMATCH]") << std::endl;
    }

    return 0;
}