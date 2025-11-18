#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/1-bit-and-2-bit-characters

class BitAnd2BitCharacters
{
public:
    // 0 ms, faster than 100% : 13.04 MB, less than 72.06%
    uint8_t solution(vector<int> bits)
    {
        int n = bits.size();
        int ones = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (bits[i] == 1) {
                ones++;
            }
            else {
                break;
            }
        }

        return ones % 2 == 0;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 0, 0 },
        { 1, 1, 1, 0 }
    };
};