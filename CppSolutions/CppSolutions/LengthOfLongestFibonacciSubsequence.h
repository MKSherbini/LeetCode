#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

class LengthOfLongestFibonacciSubsequence {
public:
    // 287 ms, faster than 59.21% : 149.8 MB, less than 34.16%
    int solution(vector<int> arr)
    {
        int n = arr.size();
        unordered_map<int, int> m;
        int ans = 0;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (size_t i = 0; i < n; i++) {
            m[arr[i]] = i;

            for (size_t j = 0; j < i; j++) {
                if (!m.count(arr[i] - arr[j])) {
                    continue;
                }

                int k = m[arr[i] - arr[j]];
                if (k < j) {
                    v[j][i] = v[k][j] + 1;
                }

                ans = max(ans, v[j][i]);
            }
        }

        return ans == 0 ? 0 : ans + 2;
    }
    vector<int> output = {
        5,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 5, 6, 7, 8 },
        { 1, 3, 7, 11, 12, 14, 18 }
    };
};