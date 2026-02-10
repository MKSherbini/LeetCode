#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-balanced-subarray-i

class LongestBalancedSubarrayI {
public:
    // 1912 ms, faster than 55.77% : 530.31 MB, less than 41.51%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> even, odd;

            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0) {
                    ++even[nums[j]];
                } else {
                    ++odd[nums[j]];
                }

                if (odd.size() == even.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
    // WA doesnt count intermediate duplicates
    int solution2(vector<int> nums)
    {
        int n = nums.size();
        unordered_map<int, int> even, odd;
        vector<int> evenPre(n), oddPre(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ++even[nums[i]];
            } else {
                ++odd[nums[i]];
            }
            evenPre[i] = even.size();
            oddPre[i] = odd.size();
        }

        Printer::print(evenPre);
        Printer::print(oddPre);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (evenPre[j]
                        - (i > 0 ? evenPre[i - 1] : 0)
                    == oddPre[j] - (i > 0 ? oddPre[i - 1] : 0))
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
    vector<int> output = {
        4,
        5,
        3,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 5, 4, 3 },
        { 3, 2, 2, 5, 4 },
        { 1, 2, 3, 2 },
        { 10, 6, 10, 7 }
    };
};