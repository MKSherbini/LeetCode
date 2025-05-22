#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/zero-array-transformation-iii

class ZeroArrayTransformationIII {
public:
    // 83 ms, faster than 88.55% : 223.95 MB, less than 95.5%
    int solution(vector<int> nums, vector<vector<int>> queries)
    {
        int n = nums.size(), m = queries.size();
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        Printer::print(queries);
        vector<int> v(n);
        priority_queue<int> pq;
        int cur = 0, j = 0;
        for (int i = 0; i < n; i++) {
            cur += v[i];
            while (j < m && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }
            while (nums[i] - cur > 0) {
                Printer::print(i, nums[i] - cur);
                if (pq.empty() || pq.top() < i) {
                    return -1;
                } else {
                    cur++;
                    if (pq.top() + 1 < n)
                        v[pq.top() + 1]--;
                    pq.pop();
                }
            }
        }
        Printer::print(nums);

        return pq.size();
    }
    vector<int> output = {
        1,
        2,
        -1,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 0, 2 },
        { 1, 1, 1, 1 },
        { 1, 2, 3, 4 },
        { 0, 0, 3 }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 2 }, { 0, 2 }, { 1, 1 } },
        { { 1, 3 }, { 0, 2 }, { 1, 3 }, { 1, 2 } },
        { { 0, 3 } },
        { { 0, 2 }, { 1, 1 }, { 0, 0 }, { 0, 0 } }
    };
};