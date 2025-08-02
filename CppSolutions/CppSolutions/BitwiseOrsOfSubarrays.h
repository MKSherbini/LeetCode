#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/bitwise-ors-of-subarrays

class BitwiseOrsOfSubarrays {
public:
    // 1075 ms, faster than 46.93% : 339.91 MB, less than 11.47%
    int solution(vector<int> arr)
    {
        int n = arr.size();
        unordered_set<int> ans, cur;
        cur.insert(arr[0]);
        ans.insert(arr[0]);
        for (int i = 1; i < n; i++) {
            unordered_set<int> t;
            t.insert(arr[i]);
            for (auto y : cur) {
                t.insert(arr[i] | y);
            }
            cur = t;
            ans.insert(cur.begin(), cur.end());
        }

        return ans.size();
    }
    vector<int> output = {
        1,
        3,
        6
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 0 },
        { 1, 1, 2 },
        { 1, 2, 4 }
    };
};