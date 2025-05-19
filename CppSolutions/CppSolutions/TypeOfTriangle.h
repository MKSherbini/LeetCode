#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/type-of-triangle

class TypeOfTriangle {
public:
    // 0 ms, faster than 100% : 22.76 MB, less than 88.05%
    string solution(vector<int> nums)
    {
        if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0])
            return "none";

        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        else if (nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2])
            return "scalene";
        else
            return "isosceles";
    }
    vector<string> output = {
        "equilateral",
        "scalene"
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 3, 3 },
        { 3, 4, 5 }
    };
};