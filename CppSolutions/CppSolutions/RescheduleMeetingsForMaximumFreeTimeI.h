#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i

class RescheduleMeetingsForMaximumFreeTimeI {
public:
    // 0 ms, faster than 100% : 123.24 MB, less than 79.76%
    int solution(int eventTime, int k, vector<int> startTime, vector<int> endTime)
    {
        int n = startTime.size();
        vector<int> pre(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + endTime[i] - startTime[i];
            if (i >= k - 1) {
                int st = i == k - 1 ? 0 : endTime[i - k];
                int end = i == n - 1 ? eventTime : startTime[i + 1];
                int used = pre[i] - (i == k - 1 ? 0 : pre[i - k]);
                ans = max(ans, end - st - used);
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        6,
        0
    };
    static constexpr int const& inputs = 4;
    vector<int> input1 = {
        5,
        10,
        5
    };
    vector<int> input2 = {
        1,
        1,
        2
    };
    vector<vector<int>> input3 = {
        { 1, 3 },
        { 0, 2, 9 },
        { 0, 1, 2, 3, 4 }
    };
    vector<vector<int>> input4 = {
        { 2, 5 },
        { 1, 4, 10 },
        { 1, 2, 3, 4, 5 }
    };
};