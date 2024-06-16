#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/patching-array/description/

class PatchingArray {
public:
    // 0 ms, faster than 100% : 13.58 MB, less than 97.87%
    int solution(vector<int> nums, int n)
    {
        long long reach = 1;
        int ans = 0;

        for (size_t i = 0; i < size(nums); i++) {
            if (reach >= nums[i]) {
                reach += nums[i];
                continue;
            }

            while (reach < nums[i] && reach <= n) {
                Printer::print(nums[i], reach);
                reach += reach;
                ans++;
            }

            reach += nums[i];
            if (reach > n)
                return ans;
        }

        while (reach <= n) {
            reach += reach;
            ans++;
        }

        return ans;
    }
    vector<int> output = {
        1,
        2,
        0,
        2,
        5,
        1,
        2,
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 3 },
        { 1, 5, 10 },
        { 1, 2, 2 },
        { 1, 7, 21, 31, 34, 37, 40, 43, 49, 87, 90, 92, 93, 98, 99 },
        { 20, 22, 39, 53, 55, 61, 65, 78, 87, 90 },
        { 1, 2, 2, 6, 34, 38, 41, 44, 47, 47, 56, 59, 62, 73, 77, 83, 87, 89, 94 },
        { 1, 2, 16, 19, 31, 35, 36, 64, 64, 67, 69, 71, 73, 74, 76, 79, 80, 91, 95, 96, 97 },
    };
    vector<int> input2 = {
        6,
        20,
        5,
        12,
        20,
        20,
        8,
    };
};