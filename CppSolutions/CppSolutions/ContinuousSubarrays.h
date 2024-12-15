#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/continuous-subarrays

class ContinuousSubarrays {
public:
    // 69 ms, faster than 97.17% : 112.77 MB, less than 89.16%
    long long solution(vector<int> nums)
    {
        int n = size(nums);
        long long ans = 0;
        map<int, int> m;
        int i = 0;
        for (size_t j = 0; j < n; j++) {
            m[nums[j]]++;

            while (m.rbegin()->first - m.begin()->first > 2) {
                m[nums[i]]--;
                if (!m[nums[i]])
                    m.erase(nums[i]);
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }
    vector<int> output = {
        8,
        6
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 5, 4, 2, 4 },
        { 1, 2, 3 }
    };
};