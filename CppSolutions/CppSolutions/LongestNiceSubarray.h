#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-nice-subarray

class LongestNiceSubarray {
public:
    // 54 ms, faster than 22.26% : 60.85 MB, less than 87.22%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        vector<int> freq(32, 0);

        int i = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            int dub = 0;
            for (int k = 0, b = 1; k < freq.size(); k++, b <<= 1) {
                freq[k] += (nums[j] & b) ? 1 : 0;
                dub += (freq[k] > 1);
            }

            Printer::print(freq);
            while (dub) {
                for (int k = 0, b = 1; k < freq.size(); k++, b <<= 1) {
                    dub -= (freq[k] > 1);
                    freq[k] -= (nums[i] & b) ? 1 : 0;
                }
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
    vector<int> output = {
        3,
        1,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 3, 8, 48, 10 },
        { 3, 1, 5, 11, 13 },
        { 536870913, 536870914 }
    };
};