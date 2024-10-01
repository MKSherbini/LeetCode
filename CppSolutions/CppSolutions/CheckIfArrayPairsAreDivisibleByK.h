#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

class CheckIfArrayPairsAreDivisibleByK {
public:
    // 69 ms, faster than 96.56% : 64.2 MB, less than 94.58%
    uint8_t solution(vector<int> arr, int k)
    {
        vector<int> v(k);
        for (auto x : arr)
            v[(x % k + k) % k]++;

        if (v[0] % 2)
            return 0;

        for (size_t i = 1; i <= k / 2; i++) {
            Printer::print(i, k - i, v[i], v[k - i]);
            if (v[i] != v[k - i])
                return 0;
        }

        return 1;
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 5, 10, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6 },
        { 1, 2, 3, 4, 5, 6 }
    };
    vector<int> input2 = {
        5,
        7,
        10
    };
};