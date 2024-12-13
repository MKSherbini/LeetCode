#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements

class FindScoreOfAnArrayAfterMarkingAllElements {
public:
    // 151 ms, faster than 35.27% : 102.21 MB, less than 83.96%
    int solution(vector<int> nums)
    {
        int n = size(nums);
        auto cmp = [&](const auto i, const auto j) {
            return nums[i] == nums[j] ? i > j : nums[i] > nums[j];
        };

        priority_queue<int, vector<int>, decltype(cmp)>
            pq(cmp);
        for (size_t i = 0; i < n; i++) {
            pq.push(i);
        }
        Printer::print(pq);

        long long ans = 0;
        vector<int> vis(n);
        while (!empty(pq)) {
            auto i = pq.top();
            pq.pop();

            if (vis[i])
                continue;

            vis[i] = 1;
            ans += nums[i];
            if (i > 0)
                vis[i - 1] = 1;
            if (i < n - 1)
                vis[i + 1] = 1;
        }

        return ans;
    }
    vector<int> output = {
        7,
        5
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 1, 3, 4, 5, 2 },
        { 2, 3, 5, 1, 3, 2 }
    };
};