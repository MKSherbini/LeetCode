#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-complete-subarrays-in-an-array

class CountCompleteSubarraysInAnArray {
public:
    // 10 ms, faster than 92.79% : 40.11 MB, less than 93.59%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[nums[i]]++;

        int cnt = m.size();
        int ans = 0;
        int i = 0;
        m.clear();
        for (int j = 0; j < n; j++) {
            m[nums[j]]++;
            while (m.size() == cnt) {
                Printer::print(i, j);
                ans += n - j;
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
        }

        return ans;
    }
    vector<int> output = {
        4,
        10
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 3, 1, 2, 2 },
        { 5, 5, 5, 5 }
    };
};