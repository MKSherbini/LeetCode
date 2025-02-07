#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

class FindTheNumberOfDistinctColorsAmongTheBalls {
public:
    // 101 ms, faster than 91.64% : 155.51 MB, less than 89.39%
    vector<int> solution(int limit, vector<vector<int>> queries)
    {
        unordered_map<int, int> m;
        unordered_map<int, int> colors;
        vector<int> ans(size(queries));
        for (size_t i = 0; i < size(ans); i++) {
            auto& q = queries[i];

            if (!m.count(q[0])) {
                m[q[0]] = q[1];
                colors[q[1]]++;
            }
            else if (m[q[0]] != q[1]) {
                if (--colors[m[q[0]]] == 0) {
                    colors.erase(m[q[0]]);
                }

                m[q[0]] = q[1];
                colors[q[1]]++;
            }

            ans[i] = size(colors);
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 1, 2, 2, 3 },
        { 1, 2, 2, 3, 4 }
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        4,
        4
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 4 }, { 2, 5 }, { 1, 3 }, { 3, 4 } },
        { { 0, 1 }, { 1, 2 }, { 2, 2 }, { 3, 4 }, { 4, 5 } }
    };
};