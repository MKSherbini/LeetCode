#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii

class RescheduleMeetingsForMaximumFreeTimeII {
public:
    // 0 ms, faster than 100% : 142.05 MB, less than 86.45%
    int solution(int eventTime, vector<int> startTime, vector<int> endTime)
    {
        int n = startTime.size();
        vector<int> post(n);
        post[n - 1] = eventTime - endTime[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            post[i] = max(post[i + 1], startTime[i + 1] - endTime[i]);
        }

        int ans = 0;
        int pre = 0, pre2 = 0;
        for (int i = 0; i < n; ++i) {
            int gpStart = i == 0 ? 0 : endTime[i - 1];
            int gpEnd = i == n - 1 ? eventTime : startTime[i + 1];
            pre = pre2;
            pre2 = max(pre2, startTime[i] - gpStart);
            int dur = endTime[i] - startTime[i];
            if (pre >= dur || (i + 1 < n && post[i + 1] >= dur)) {
                ans = max(ans, gpEnd - gpStart);
            } else {
                ans = max(ans, gpEnd - gpStart - dur);
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        7,
        6,
        0,
        4
    };
    static constexpr int const& inputs = 3;
    vector<int> input1 = {
        5,
        10,
        10,
        5,
        59
    };
    vector<vector<int>> input2 = {
        { 1, 3 },
        { 0, 7, 9 },
        { 0, 3, 7, 9 },
        { 0, 1, 2, 3, 4 },
        { 0, 2, 3, 12, 47, 48, 50, 55 }
    };
    vector<vector<int>> input3 = {
        { 2, 5 },
        { 1, 8, 10 },
        { 1, 4, 8, 10 },
        { 1, 2, 3, 4, 5 },
        { 2, 3, 12, 47, 48, 49, 55, 56 }
    };
};