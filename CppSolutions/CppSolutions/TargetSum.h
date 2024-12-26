#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/target-sum

class TargetSum {
public:
    // 23 ms, faster than 52.06% : 26.35 MB, less than 25.06%
    int solution(vector<int> nums, int target)
    {
        int mx = accumulate(begin(nums), end(nums), 0);
        int n = size(nums);
        vector mem(n, vector(2 * mx + 1, -1));
        function<int(int, int)> f = [&](int i, int sum) -> int {
            if (i == n)
                return sum == target;

            if (mem[i][sum + mx] != -1)
                return mem[i][sum + mx];

            return mem[i][sum + mx] = f(i + 1, sum + nums[i])
                + f(i + 1, sum - nums[i]);
        };

        return f(0, 0);
    }

    // 163 ms, faster than 44.62% : 61.11 MB, less than 12.36%
    int solution2(vector<int> nums, int target)
    {
        int n = size(nums);
        vector<unordered_map<int, int>> mem(n);
        function<int(int, int)> f = [&](int i, int sum) -> int {
            if (i == n)
                return sum == target;

            if (mem[i].count(sum))
                return mem[i][sum];

            return mem[i][sum] = f(i + 1, sum + nums[i])
                + f(i + 1, sum - nums[i]);
        };

        return f(0, 0);
    }
    vector<int> output = {
        5,
        1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 1, 1, 1, 1 },
        { 1 }
    };
    vector<int> input2 = {
        3,
        1
    };
};