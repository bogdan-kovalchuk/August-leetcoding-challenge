#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res;
        return res;
    }
};

int main() {
    int candies = 10, num_people = 3;

    Solution solution;
    auto res = solution.distributeCandies(candies, num_people);

    for (auto r : res) {
        cout << r << " ";
    }

    return 0;
}