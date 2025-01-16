#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/bitwise-xor-of-all-pairings

class BitwiseXorOfAllPairings {
public:
    // 0 ms, faster than 100% : 64.19 MB, less than 83.4%
    int solution(vector<int> nums1, vector<int> nums2)
    {
        int n = size(nums1), m = size(nums2);

        int ans = 0;
        if (n & 1) {
            for (auto x : nums2)
                ans ^= x;
        }

        if (m & 1) {
            for (auto x : nums1)
                ans ^= x;
        }

        return ans;
    }
    vector<int> output = {
        13,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 1, 3 },
        { 1, 2 }
    };
    vector<vector<int>> input2 = {
        { 10, 2, 5, 0 },
        { 3, 4 }
    };
};