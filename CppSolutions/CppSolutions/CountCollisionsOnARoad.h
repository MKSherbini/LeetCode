#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-collisions-on-a-road

class CountCollisionsOnARoad {
public:
    // 11 ms, faster than 65.2% : 18.97 MB, less than 100%
    int solution(string directions)
    {
        int n = directions.size();
        int ans = 0;
        int r = 0;
        int startBlocked = 0;
        for (auto c : directions) {
            if (c == 'S') {
                startBlocked = 1;
                ans += r;
                r = 0;
                continue;
            } else if (c == 'L' && r > 0) {
                startBlocked = 1;
                ans += r;
                ans++;
                r = 0;
            } else if (c == 'L' && startBlocked) {
                ans++;
            } else if (c == 'R') {
                r++;
            }
            Printer::print(c, r, ans);
        }

        return ans;
    }
    vector<int> output = {
        5,
        0,
        11
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "RLRSLL",
        "LLRR",
        "LLSRSSRSSLLSLLLRSLSRL"
    };
};