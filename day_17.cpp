#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        if (candies == 0) return {};
        int j = 0, given = 0;
        vector<int> res(num_people, 0);
        while (candies > 0) {
            if (j >= num_people) j = 0;
            candies >= ++given ? res[j] += given : res[j] += candies;
            candies -= given;
            ++j;
        }
        return res;
    }
};

int main() {
    int candies = 60, num_people = 4;

    Solution solution;
    auto res = solution.distributeCandies(candies, num_people);

    for (auto r : res) {
        cout << r << " ";
    }

    return 0;
}