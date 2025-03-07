#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/closest-prime-numbers-in-range

class ClosestPrimeNumbersInRange {
public:
    // 230 ms, faster than 41.11% : 158.74 MB, less than 17.22%
    vector<int> solution(int left, int right)
    {
        vector<int> sieve(right + 1, 1);
        sieve[0] = 0;
        sieve[1] = 0;
        for (size_t i = 2; i <= right; i++) {
            if (sieve[i] != 1)
                continue;

            for (size_t j = i * 2; j <= right; j += i) {
                sieve[j] = 0;
            }
        }

        int minDiff = INT_MAX;
        int last = -1, ans = -1;
        for (int i = left; i <= right; i++) {
            if (sieve[i] != 1)
                continue;

            if (last != -1 && minDiff > i - last) {
                minDiff = i - last;
                ans = last;
            }

            last = i;
        }

        if (ans == -1)
            return { -1, -1 };
  
        return { ans, ans + minDiff };
    }
    vector<vector<int>> output = {
        { 11, 13 },
        { -1, -1 }
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        10,
        4
    };
    vector<int> input2 = {
        19,
        6
    };
};