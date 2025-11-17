#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class CheckIfAll1sAreAtLeastLengthKPlacesAway {
public:
    // 0 ms, faster than 100% : 61.25 MB, less than 97.09%
    uint8_t solution(vector<int> nums, int k)
    {
        int zeros = k + 1;
        for (auto x : nums) {
            if (x == 1) {
                if (zeros < k) {
                    return false;
                }
                zeros = 0;
            } else {
                zeros++;
            }
        }

        return true;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 0, 0, 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 0, 1 }
    };
    vector<int> input2 = {
        2,
        2
    };
};