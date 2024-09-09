#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/spiral-matrix-iv/description/

class SpiralMatrixIV {
public:
    // 155 ms, faster than 82.54% : 130.34 MB, less than 94.8%
    vector<vector<int>> solution(int n, int m, ListNode* head)
    {
        vector ans(n, vector<int>(m, -1));
        const vector<pair<int, int>> dir = {
            { 0, 1 },
            { 1, 0 },
            { 0, -1 },
            { -1, 0 },
        };

        int i = 0, j = 0, cur = 0, lvl = 0;
        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= lvl && x < n - lvl;
        };

        while (head) {
            ans[i][j] = head->val;
            head = head->next;

            if (!valid(i + dir[cur].first, n)
                || !valid(j + dir[cur].second, m)
                || (i + dir[cur].first == lvl && j + dir[cur].second == lvl)) {
                cur++;
            }

            if (cur == 4) {
                lvl++, cur = 0;
            }

            i += dir[cur].first, j += dir[cur].second;
        }

        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 3, 0, 2, 6, 8 }, { 5, 0, -1, -1, 1 }, { 5, 2, 4, 9, 7 } },
        { { 0, 1, 2, -1 } }
    };
    static constexpr int const& inputs = 3;
    vector<int> input1 = {
        3,
        1
    };
    vector<int> input2 = {
        5,
        4
    };
    vector<vector<int>> input3 = {
        { 3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0 },
        { 0, 1, 2 }
    };
};