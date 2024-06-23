#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

class LongestContinuousSubarrayWithAbsoluteDiffLessThanOrEqualToLimit {
public:
    // 135 ms, faster than 37.05% : 79.5 MB, less than 37.97%
    int solution(vector<int> nums, int limit)
    {
        set<int> s;
        unordered_map<int, int> m;
        int i = 0, j = 0, n = size(nums);

        int ans = 0, cur = 0;
        while (j < n) {
            cur++;
            m[nums[j]]++;
            s.insert(nums[j]);
            j++;

            while (!empty(s) && *s.rbegin() - *s.begin() > limit) {
                cur--;
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    s.erase(nums[i]);
                i++;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
    vector<int> output = {
        2,
        4,
        3
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 8, 2, 4, 7 },
        { 10, 1, 2, 4, 7, 2 },
        { 4, 2, 2, 2, 4, 4, 2, 2 }
    };
    vector<int> input2 = {
        4,
        5,
        0
    };
};