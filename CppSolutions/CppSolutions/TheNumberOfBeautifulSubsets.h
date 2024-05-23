#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

class TheNumberOfBeautifulSubsets {
public:
    // WA
    int solution(vector<int> nums, int k)
    {
        unordered_map<int, int> f;
        for (auto x : nums)
            f[x]++;

        int n = size(nums);
        long long ans = 1LL << n;
        for (auto [x, c] : f) {
            int ava = (f.count(x + k) ? f[x + k] : 0);
            ans -= (1 << ava) * ((1 << c) - 1);
            Printer::print(ava, ans);
        }

        return ans;
    }

    // WA
    int solution2(vector<int> nums, int k)
    {
        unordered_map<int, int> f;
        for (auto x : nums)
            f[x]++;

        int n = size(nums);
        int ans = 0;
        for (auto [x, c] : f) {
            n -= c;
            int ava = max(0, n - (f.count(x + k) ? f[x + k] : 0) - (f.count(x - k) ? f[x - k] : 0));
            int subsets = (1 << c) - 1, rest = (1 << ava);
            ans += subsets * rest;
            Printer::print(n, ava, subsets, rest, ans);
        }

        return ans;
    }
    vector<int> output = {
        23,
        4,
        1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 2, 5, 9, 10, 3 },
        { 2, 4, 6 },
        { 1 }
    };
    vector<int> input2 = {
        1,
        2,
        1
    };
};