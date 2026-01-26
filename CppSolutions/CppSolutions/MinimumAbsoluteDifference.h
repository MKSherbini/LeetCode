#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-absolute-difference

class MinimumAbsoluteDifference {
public:
    // 13 ms, faster than 85.69% : 36.53 MB, less than 88.73%
    vector<vector<int>> solution(vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] == minDiff) {
                ans.push_back({ arr[i - 1], arr[i] });
            }
        }

        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 1, 2 }, { 2, 3 }, { 3, 4 } },
        { { 1, 3 } },
        { { -14, -10 }, { 19, 23 }, { 23, 27 } }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 4, 2, 1, 3 },
        { 1, 3, 6, 10, 15 },
        { 3, 8, -10, 23, 19, -4, -14, 27 }
    };
};