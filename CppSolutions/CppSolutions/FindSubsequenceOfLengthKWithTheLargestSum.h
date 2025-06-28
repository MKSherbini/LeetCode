#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

class FindSubsequenceOfLengthKWithTheLargestSum {
public:
    // 0 ms, faster than 100% : 13.43 MB, less than 98.52%
    vector<int> solution(vector<int> nums, int k)
    {
        auto cmp = [&](int i, int j) {
            return nums[i] > nums[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums.size(); ++i) {
            if (pq.size() < k) {
                pq.push(i);
            } else if (nums[i] > nums[pq.top()]) {
                pq.pop();
                pq.push(i);
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(), ans.end());

        for (auto& i : ans) {
            i = nums[i];
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 3, 3 },
        { -1, 3, 4 },
        { 3, 4 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 1, 3, 3 },
        { -1, -2, 3, 4 },
        { 3, 4, 3, 3 }
    };
    vector<int> input2 = {
        2,
        3,
        2
    };
};