#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/max-chunks-to-make-sorted

class MaxChunksToMakeSorted {
public:
    // 0 ms, faster than 100% : 9.04 MB, less than 42.82%
    int solution(vector<int> arr)
    {
        int n = size(arr);
        int ans = 0;
        int s = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i], s2 += i;
            if (s == s2)
                ans++;
        }

        return ans;
    }
    vector<int> output = {
        1,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 4, 3, 2, 1, 0 },
        { 1, 0, 2, 3, 4 }
    };
};