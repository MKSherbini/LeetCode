#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class CountNumberOfNiceSubarrays {
public:
    // 83 ms, faster than 93.14% : 69.84 MB, less than 91.51%
    int solution(vector<int> nums, int k)
    {
        int n = size(nums);
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && k != 0) {
                if (nums[j++] & 1) {
                    k--;
                }
            }

            if (k != 0)
                break;

            Printer::print(i, j);
            int add = 0;
            while (i < j && (nums[i] & 1) == 0) {
                add++;
                i++;
            }
            ans += add + 1;
            Printer::print(i, j);

            while (j < n && (nums[j] & 1) == 0) {
                ans += add + 1;
                Printer::print(i, j, add);
                j++;
            }
            i++, k++;
        }

        return ans;
    }
    vector<int> output = {
        2,
        0,
        16
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 1, 2, 1, 1 },
        { 2, 4, 6 },
        { 2, 2, 2, 1, 2, 2, 1, 2, 2, 2 }
    };
    vector<int> input2 = {
        3,
        1,
        2
    };
};