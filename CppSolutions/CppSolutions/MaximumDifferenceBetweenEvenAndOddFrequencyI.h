#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i

class MaximumDifferenceBetweenEvenAndOddFrequencyI {
public:
    // 0 ms, faster than 100% : 9.13 MB, less than 94.49%
    int solution(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int evenMin = INT_MAX, oddMax = INT_MIN;
        for (int f : freq) {
            if (f == 0)
                continue;

            Printer::print(f, evenMin, oddMax);
            if (f % 2 == 0) {
                evenMin = min(evenMin, f);
            } else {
                oddMax = max(oddMax, f);
            }
        }

        return oddMax - evenMin;
    }
    vector<int> output = {
        3,
        1
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "aaaaabbc",
        "abcabcab"
    };
};