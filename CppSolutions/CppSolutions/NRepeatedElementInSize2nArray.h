#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class NRepeatedElementInSize2nArray {
public:
    // 0 ms, faster than 100% : 28.34 MB, less than 87.61%
    int solution(vector<int> nums)
    {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return num;
            }
            seen.insert(num);
        }

        return 66;
    }
    vector<int> output = {
        3,
        2,
        5
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 3 },
        { 2, 1, 2, 5, 3, 2 },
        { 5, 1, 5, 2, 5, 3, 5, 4 }
    };
};