#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-time-difference/description/

class MinimumTimeDifference {
public:
    // 88 ms, faster than 5.83% : 18.2 MB, less than 29.03%
    int solution(vector<string> timePoints)
    {
        auto f = [&](const string& s) {
            return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        };

        sort(begin(timePoints), end(timePoints),
            [&](const auto& a, const auto& b) { return f(a) < f(b); });

        int ans = 1440 + f(timePoints[0]) - f(timePoints.back());
        for (size_t i = 1; i < size(timePoints); i++) {
            ans = min(ans, f(timePoints[i]) - f(timePoints[i - 1]));
        }

        return ans;
    }
    vector<int> output = {
        1,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "23:59", "00:00" },
        { "00:00", "23:59", "00:00" }
    };
};