#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

class MaximumCandiesAllocatedToKChildren {
public:
    // 22 ms, faster than 77.72 % : 88.1 MB, less than 97.17%
    int solution(vector<int> candies, int k)
    {
        int n = candies.size();

        auto f = [&](int c) -> bool {
            if (c == 0)
                return true;

            long long cnt = 0;
            for (auto x : candies) {
                cnt += x / c;
                if (cnt >= k) {
                    return true;
                }
            }

            return false;
        };

        int l = 0, r = 1e7 + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            Printer::print(l, r, mid, f(mid));
            if (f(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        Printer::print(l, r);
        return r - 1;
    }
    vector<int> output = {
        5,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 5, 8, 6 },
        { 2, 5 }
    };
    vector<int> input2 = {
        3,
        11
    };
};