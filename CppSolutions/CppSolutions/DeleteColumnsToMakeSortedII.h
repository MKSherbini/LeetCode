#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/delete-columns-to-make-sorted-ii

class DeleteColumnsToMakeSortedII {
public:
    // 0 ms, faster than 100% : 12.8 MB, less than 86.77%
    int solution(vector<string> strs)
    {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int deleteCount = 0;
        for (int col = 0; col < m; ++col) {
            bool needDelete = false;
            for (int row = 0; row < n - 1; ++row) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    needDelete = true;
                    break;
                }
            }
            if (needDelete) {
                ++deleteCount;
            } else {
                for (int row = 0; row < n - 1; ++row) {
                    if (strs[row][col] < strs[row + 1][col]) {
                        sorted[row] = true;
                    }
                }
            }
        }
        return deleteCount;
    }
    vector<int> output = {
        1,
        0,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "ca", "bb", "ac" },
        { "xc", "yb", "za" },
        { "zyx", "wvu", "tsr" }
    };
};