#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i

class FindTheMaximumLengthOfValidSubsequenceI {
public:
    // 0 ms, faster than 100% : 95.84 MB, less than 100%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int evens = 0, alt = 0;
        bool last = !(nums[0] % 2);
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                evens++;
            }
            if (nums[i] % 2 != last) {
                alt++;
                last = !last;
            }
        }

        return max(max(evens, n - evens), alt);
    }
    vector<int> output = {
        4,
        6,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4 },
        { 1, 2, 1, 1, 2, 1, 2 },
        { 1, 3 }
    };
};