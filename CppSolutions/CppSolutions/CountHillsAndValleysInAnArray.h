#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-hills-and-valleys-in-an-array

class CountHillsAndValleysInAnArray {
public:
    // 0 ms, faster than 100% : 11.96 MB, less than 96.23%
    int solution(vector<int> nums)
    {
        int beforeLast = -1, last = -1, ans = 0;
        for (auto num : nums) {
            if (last == -1) {
                last = num;
                continue;
            }
            if (last == num) {
                continue;
            }

            if (beforeLast != -1) {
                if ((beforeLast < last && last > num) || (beforeLast > last && last < num)) {
                    ans++;
                }
                Printer::print(beforeLast, last, num, ans);
            }

            beforeLast = last;
            last = num;
        }

        return ans;
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 4, 1, 1, 6, 5 },
        { 6, 6, 5, 5, 4, 1 }
    };
};