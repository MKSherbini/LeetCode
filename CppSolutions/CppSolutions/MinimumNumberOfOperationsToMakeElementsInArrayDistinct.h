#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct

class MinimumNumberOfOperationsToMakeElementsInArrayDistinct {
public:
    // 0 ms, faster than 100% : 28.17 MB, less than 40.79%
    int solution(vector<int> nums)
    {
        unordered_map<int, int> m;
        for (auto x : nums)
            m[x]++;
        int i = 0;
        int n = size(nums);
        for (i = 0; i < n; i++) {
            if (n - i == size(m))
                break;
            if (--m[nums[i]] == 0)
                m.erase(nums[i]);
        }

        return (i + 2) / 3;
    }
    vector<int> output = {
        2,
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 2, 3, 3, 5, 7 },
        { 4, 5, 6, 4, 4 },
        { 6, 7, 8, 9 }
    };
};