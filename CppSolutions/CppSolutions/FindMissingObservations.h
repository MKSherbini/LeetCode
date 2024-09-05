#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-missing-observations/description/

class FindMissingObservations {
public:
    // 79 ms, faster than 95.62% : 126.13 MB, less than 35.77%
    vector<int> solution(vector<int> rolls, int mean, int n)
    {
        int m = size(rolls);
        int sum = accumulate(begin(rolls), end(rolls), 0);
        int requiredSum = mean * (n + m) - sum;

        Printer::print(requiredSum);
        if (requiredSum > 6 * n || requiredSum < n)
            return {};

        vector<int> ans;
        while (n--) {
            int x = min(6, requiredSum - n);
            ans.push_back(x);
            requiredSum -= x;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 6, 6 },
        { 2, 3, 2, 2 },
        {},
        { 5 }
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 3, 2, 4, 3 },
        { 1, 5, 6 },
        { 1, 2, 3, 4 },
        { 1 }
    };
    vector<int> input2 = {
        4,
        3,
        6,
        3
    };
    vector<int> input3 = {
        2,
        4,
        4,
        1
    };
};