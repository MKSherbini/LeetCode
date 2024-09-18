#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/largest-number/description/

class LargestNumber {
public:
    // 3 ms, faster than 93.74% : 15.32 MB, less than 98.62%
    string solution(vector<int> nums)
    {
        sort(begin(nums), end(nums), [](const auto& a, const auto& b) -> bool {
            auto aa = to_string(a), bb = to_string(b);
            return aa + bb > bb + aa;
        });

        if (!nums[0])
            return "0";

        string ans;
        for (auto& num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
    vector<string> output = {
        "210",
        "9534330"
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 10, 2 },
        { 3, 30, 34, 5, 9 }
    };
};