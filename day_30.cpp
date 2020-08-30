#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int n) : uni(n) {
        for (int i = 0; i < n; i++) {
            uni[i] = i;
        }
    }

    void Union(int x, int y) {
        uni[Find(x)] = uni[Find(y)];
    }

    int Find(int x) {
        if (uni[x] != x) {
            uni[x] = Find(uni[x]);
        }
        return uni[x];
    }

private:
    vector<int> uni;
};

class Solution {
public:
    int largestComponentSize(vector<int> &A) {
        int n = *max_element(A.begin(), A.end());
        UnionFind union_find(n + 1);
        for (const int &a : A) {
            for (int k = 2; k <= sqrt(a); k++) {
                if (a % k == 0) {
                    union_find.Union(a, k);
                    union_find.Union(a, a / k);
                }
            }
        }

        unordered_map<int, int> mp;
        int ans = 1;
        for (int &a : A) {
            ans = max(ans, ++mp[union_find.Find(a)]);
        }
        return ans;
    }
};

int main() {
    vector<int> A = {2, 3, 6, 7, 4, 12, 21, 39};
    Solution solution;
    cout << solution.largestComponentSize(A) << endl;
    return 0;
}