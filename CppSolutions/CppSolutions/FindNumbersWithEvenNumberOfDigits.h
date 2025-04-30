#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class FindNumbersWithEvenNumberOfDigits {
public:
    // 0 ms, faster than 100% : 14.3 MB, less than 18.15%
    int solution(vector<int> nums)
    {
        int ans = 0;
        for (int num : nums) {
            if (to_string(num).length() % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
    vector<int> output = {
        2,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 12, 345, 2, 6, 7896 },
        { 555, 901, 482, 1771 }
    };
};