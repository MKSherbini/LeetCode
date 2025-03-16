#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-time-to-repair-cars

class MinimumTimeToRepairCars {
public:
    // 12 ms, faster than 93.97% : 59.2 MB, less than 96.42%
    int solution(vector<int> ranks, int cars)
    {
        int n = ranks.size();

        auto f = [&](long long t) -> bool {
            long long done = 0;
            for (auto x : ranks) {
                done += sqrt(t / x);
                if (done >= cars) {
                    return true;
                }
            }

            return false;
        };

        long long l = 0, r = 1e14 + 1;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            Printer::print(l, r, mid, f(mid));
            if (f(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        Printer::print(l, r);
        return r;
    }
    vector<int> output = {
        16,
        16
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 2, 3, 1 },
        { 5, 1, 8 }
    };
    vector<int> input2 = {
        10,
        6
    };
};