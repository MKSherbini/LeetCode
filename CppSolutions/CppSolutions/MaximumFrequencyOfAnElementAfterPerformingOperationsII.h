#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii

class MaximumFrequencyOfAnElementAfterPerformingOperationsII {
public:
    // 1048 ms, faster than 39.43% : 280.64 MB, less than 36.29%
    int solution(vector<int> nums, int k, int numOperations)
    {
        map<int, int> m;
        map<int, int> c;
        for (auto x : nums) {
            c[x]++;
            m[x - k]++;
            m[x + k + 1]--;
        }

        auto it = c.begin();
        int cur = 0, ans = 0;
        for (auto [k, v] : m) {
            while (it != c.end() && it->first < k) {
                ans = max(ans, min(cur, it->second + numOperations));
                it++;
            }
            cur += v;
            ans = max(ans, min(cur, c[k] + numOperations));
            // Printer::print(k, c[k], cur);
        }

        return ans;
    }
    vector<int> output = {
        2,
        2
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 1, 4, 5 },
        { 5, 11, 20, 20 }
    };
    vector<int> input2 = {
        1,
        5
    };
    vector<int> input3 = {
        2,
        1
    };
};