#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rects;

    Solution(vector<vector<int>> rects) : rects(rects) {
    }

    vector<int> pick() {
        vector<int> rec;
        int sum = 0;

        for (auto r : rects) {
            int a = area(r);
            sum += a;

            if (rand() % sum < a)
                rec = r;
        }

        int p_x = rand() % (rec[2] - rec[0] + 1) + rec[0];
        int p_y = rand() % (rec[3] - rec[1] + 1) + rec[1];

        return {p_x, p_y};
    }

    int area(const vector<int> &r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
};

int main() {
    vector<vector<int>> rects = {{-2, -2, -1, -1},
                                 {1,  0,  3,  0}};
    auto obj = new Solution(rects);
    auto param_1 = obj->pick();
    return 0;
}


