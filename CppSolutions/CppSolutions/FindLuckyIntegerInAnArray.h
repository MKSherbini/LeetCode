#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-lucky-integer-in-an-array

class FindLuckyIntegerInAnArray {
public:
    // 0 ms, faster than 100% : 13.74 MB, less than 85.9%
    int solution(vector<int> arr)
    {
        map<int, int> m;
        for (auto& x : arr) {
            m[x]++;
        }

        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            if (it->first == it->second) {
                return it->first;
            }
        }

        return -1;
    }
    vector<int> output = {
        2,
        3,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 2, 3, 4 },
        { 1, 2, 2, 3, 3, 3 },
        { 2, 2, 2, 3, 3 }
    };
};