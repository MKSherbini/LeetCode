#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/rearranging-fruits

class RearrangingFruits {
public:
    // 53 ms, faster than 60.84% : 88.19 MB, less than 91.61%
    int solution(vector<int> basket1, vector<int> basket2)
    {
        map<int, int> m;
        int mn = INT_MAX;
        for (auto x : basket1)
            m[x]++, mn = min(mn, x);
        for (auto x : basket2)
            m[x]--, mn = min(mn, x);

        int cnt = 0;
        for (auto& [x, c] : m) {
            if (c % 2)
                return -1;

            c /= 2;
            cnt += abs(c);
            c = abs(c);
        }

        Printer::print(m);
        long long ans = 0;
        cnt /= 2;
        for (auto& [x, c] : m) {
            ans += 1ll * min(cnt, c) * min(2 * mn, x);
            cnt -= c;
            if (cnt <= 0)
                break;
        }

        return ans;
    }
    vector<int> output = {
        1,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 2, 2, 2 },
        { 2, 3, 4, 1 }
    };
    vector<vector<int>> input2 = {
        { 1, 4, 1, 2 },
        { 3, 2, 5, 1 }
    };
};