#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting

class MaximumEmployeesToBeInvitedToAMeeting {
public:
    // 11 ms, faster than 96.72% : 93.1 MB, less than 90.16%
    int solution(vector<int> favorite)
    {
        int n = size(favorite);
        vector<int> in(n);
        for (size_t i = 0; i < n; i++) {
            in[favorite[i]]++;
        }

        queue<int> q;
        for (size_t i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<int> d(n, 1);
        while (!empty(q)) {
            auto cur = q.front();
            q.pop();

            auto nxt = favorite[cur];
            d[nxt] = max(d[nxt], d[cur] + 1);
            if (--in[nxt] == 0) {
                q.push(nxt);
            }
        }

        int ans = 0;
        int twos = 0;
        for (size_t i = 0; i < n; i++) {
            if (!in[i])
                continue;

            int c = 0;
            int j = i;
            while (in[j]) {
                in[j] = 0;
                j = favorite[j];
                c++;
            }
            ans = max(ans, c);
            if (c == 2) {
                twos += d[i] + d[favorite[i]];
            }
        }

        return max(ans, twos);
    }
    vector<int> output = {
        3,
        3,
        3,
        4,
        11
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 2, 0, 2 },
        { 2, 2, 1, 2 },
        { 1, 2, 0 },
        { 3, 0, 1, 4, 1 },
        { 1, 0, 3, 2, 5, 6, 7, 4, 9, 8, 11, 10, 11, 12, 10 }
    };
};