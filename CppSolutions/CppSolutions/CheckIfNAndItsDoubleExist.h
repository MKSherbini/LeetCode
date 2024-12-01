#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-n-and-its-double-exist

class CheckIfNAndItsDoubleExist {
public:
    // 0 ms, faster than 100% : 13.53 MB, less than 17.49%
    uint8_t solution(vector<int> arr)
    {
        unordered_set<int> s;
        for (auto x : arr) {
            if (s.count(x * 2) || (x % 2 == 0 && s.count(x / 2)))
                return true;

            s.insert(x);
        }

        return false;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 10, 2, 5, 3 },
        { 3, 1, 7, 11 }
    };
};