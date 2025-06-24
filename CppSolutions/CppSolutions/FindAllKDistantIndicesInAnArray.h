#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array

class FindAllKDistantIndicesInAnArray {
public:
    // 0 ms, faster than 100% : 14.52 MB, less than 90.46%
    vector<int> solution(vector<int> nums, int key, int k)
    {
        int n = nums.size();

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                for (int j = max(ans.empty() ? 0 : ans.back() + 1, i - k); j <= min(n - 1, i + k); j++) {
                    Printer::print(i, j);
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 1, 2, 3, 4, 5, 6 },
        { 0, 1, 2, 3, 4 }
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 3, 4, 9, 1, 3, 9, 5 },
        { 2, 2, 2, 2, 2 }
    };
    vector<int> input2 = {
        9,
        2
    };
    vector<int> input3 = {
        1,
        2
    };
};