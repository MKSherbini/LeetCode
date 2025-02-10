#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-number-of-bad-pairs

class CountNumberOfBadPairs {
public:
    // 57 ms, faster than 85.88% : 87.45 MB, less than 87.54%
    int solution(vector<int> nums)
    {
        int n = size(nums);
        unordered_map<int, int> m;
        for (size_t i = 0; i < n; i++) {
            m[nums[i] - i]++;
        }

        Printer::print(m);
        long long ans = 0;
        for (auto [_, c] : m) {
            n -= c;
            ans += 1ll * n * c;
        }

        return ans;
    }
    vector<int> output = {
        5,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 4, 1, 3, 3 },
        { 1, 2, 3, 4, 5 }
    };
};