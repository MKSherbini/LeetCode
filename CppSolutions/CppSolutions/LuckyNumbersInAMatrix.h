#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

class LuckyNumbersInAMatrix {
public:
    // 10 ms, faster than 93.66% : 14.35 MB, less than 19.02%
    vector<int> solution(vector<vector<int>> matrix)
    {
        int n = size(matrix), m = size(matrix[0]);
        vector<int> mn(n, INT_MAX), mx(m, INT_MIN);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                mn[i] = min(mn[i], matrix[i][j]);
                mx[j] = max(mx[j], matrix[i][j]);
            }
        }

        sort(begin(mn), end(mn));
        sort(begin(mx), end(mx));

        vector<int> ans;

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (mn[i] == mx[j]) {
                if (empty(ans) || ans.back() != mn[i])
                    ans.push_back(mn[i]);
                i++, j++;
            } else if (mn[i] < mx[j]) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 15 },
        { 12 },
        { 7 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 3, 7, 8 }, { 9, 11, 13 }, { 15, 16, 17 } },
        { { 1, 10, 4, 2 }, { 9, 3, 8, 7 }, { 15, 16, 17, 12 } },
        { { 7, 8 }, { 1, 2 } }
    };
};