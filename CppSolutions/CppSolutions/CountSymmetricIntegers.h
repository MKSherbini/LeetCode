#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-symmetric-integers

class CountSymmetricIntegers {
public:
    // 66 ms, faster than 66.07% : 9.63 MB, less than 74.11%
    int solution(int low, int high)
    {
        int ans = 0;
        for (size_t i = low; i <= high; i++) {
            auto s = to_string(i);
            int n = s.size();
            if (n % 2 == 1) {
                continue;
            }
            int sum = 0;
            for (size_t j = 0; j < n / 2; j++) {
                sum += s[j] - '0';
                sum -= s[n - j - 1] - '0';
            }
            if (sum == 0) {
                ans++;
            }
        }

        return ans;
    }
    vector<int> output = {
        9,
        4
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        1,
        1200
    };
    vector<int> input2 = {
        100,
        1230
    };
};