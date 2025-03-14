#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/zero-array-transformation-ii

class ZeroArrayTransformationII {
public:
    // 67 ms, faster than 48.61% : 346.92 MB, less than 23.35%
    int solution(vector<int> nums, vector<vector<int>> queries)
    {
        int n = nums.size(), m = queries.size();

        auto f = [&](int k) -> bool {
            vector<int> v(n);
            for (int i = 0; i <= k; i++) {
                v[queries[i][0]] += queries[i][2];
                if (queries[i][1] + 1 < n) {
                    v[queries[i][1] + 1] -= queries[i][2];
                }
            }

            if (nums[0] - v[0] > 0) {
                return false;
            }

            for (int i = 1; i < n; i++) {
                v[i] += v[i - 1];
                if (nums[i] - v[i] > 0) {
                    return false;
                }
            }

            return true;
        };

        for (int i = -1; i < m; i++) {
            cout << f(i) << endl;
        }

        int l = -1, r = m - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return f(r) ? r + 1 : -1;
    }
    vector<int> output = {
        2,
        -1,
        0,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 0, 2 },
        { 4, 3, 2, 1 },
        { 0, 0, 0 },
        { 7, 6, 8 },
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 2, 1 }, { 0, 2, 1 }, { 1, 1, 3 } },
        { { 1, 3, 2 }, { 0, 2, 1 } },
        { { 0, 0, 2 }, { 0, 1, 5 }, { 2, 2, 5 }, { 0, 2, 4 } },
        { { 0, 0, 2 }, { 0, 1, 5 }, { 2, 2, 5 }, { 0, 2, 4 } }
    };
};