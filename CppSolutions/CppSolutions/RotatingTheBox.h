#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/rotating-the-box

class RotatingTheBox {
public:
    // 178 ms, faster than 92.15% : 56.22 MB, less than 85.61%
    vector<vector<char>> solution(vector<vector<char>> box)
    {
        int n = size(box), m = size(box[0]);
        vector ans(m, vector<char>(n));

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                ans[j][n - i - 1] = box[i][j];
            }
        }

        for (size_t j = 0; j < n; j++) {
            int c = 0;
            for (size_t i = 0; i < m; i++) {
                if (ans[i][j] == '#') {
                    c++, ans[i][j] = '.';
                } else if (ans[i][j] == '*') {
                    for (int k = i - 1; c; c--, k--) {
                        ans[k][j] = '#';
                    }
                }
            }
            for (int k = m - 1; c; c--, k--) {
                ans[k][j] = '#';
            }
        }

        Printer::print(box);
        return ans;
    }
    vector<vector<vector<char>>> output = {
        { { '.' }, { '#' }, { '#' } },
        { { '#', '.' }, { '#', '#' }, { '*', '*' }, { '.', '.' } },
        { { '.', '#', '#' }, { '.', '#', '#' }, { '#', '#', '*' }, { '#', '*', '.' }, { '#', '.', '*' }, { '#', '.', '.' } }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<char>>> input1 = {
        { { '#', '.', '#' } },
        { { '#', '.', '*', '.' }, { '#', '#', '*', '.' } },
        { { '#', '#', '*', '.', '*', '.' }, { '#', '#', '#', '*', '.', '.' }, { '#', '#', '#', '.', '#', '.' } }
    };
};