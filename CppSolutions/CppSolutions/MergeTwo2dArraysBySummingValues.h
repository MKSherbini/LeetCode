#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

class MergeTwo2dArraysBySummingValues {
public:
    // 0 ms, faster than 100% : 14.88 MB, less than 44.73%
    vector<vector<int>> solution(vector<vector<int>> nums1, vector<vector<int>> nums2)
    {
        unordered_map<int, int> m;
        for (auto &x : nums1) {
            m[x[0]] = x[1];
        }
        for (auto &x : nums2) {
            if (!m.count(x[0]))
                continue;

            x[1] += m[x[0]];
            m.erase(x[0]);
        }

        for (auto &x : m) {
			nums2.push_back({ x.first, x.second });
		}

        sort(nums2.begin(), nums2.end());
		return nums2;
    }
    vector<vector<vector<int>>> output = {
        { { 1, 6 }, { 2, 3 }, { 3, 2 }, { 4, 6 } },
        { { 1, 3 }, { 2, 4 }, { 3, 6 }, { 4, 3 }, { 5, 5 } }
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 2, 3 }, { 4, 5 } },
        { { 2, 4 }, { 3, 6 }, { 5, 5 } }
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 4 }, { 3, 2 }, { 4, 1 } },
        { { 1, 3 }, { 4, 3 } }
    };
};