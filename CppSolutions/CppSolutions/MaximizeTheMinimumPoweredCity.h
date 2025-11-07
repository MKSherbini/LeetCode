#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximize-the-minimum-powered-city

class MaximizeTheMinimumPoweredCity {
public:
    // 119 ms, faster than 47.33% : 314.74 MB, less than 32.91%
    int solution(vector<int> stations, int r, int k)
    {
        int n = stations.size();
        vector<long long> power(n);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            power[left] += stations[i];
            if (right < n) {
                power[right] -= stations[i];
            }
        }

        auto f = [&](long long x) {
            vector<long long> extra(n);
            long long curr = 0;
            long long rem = k;
            for (int i = 0; i < n; i++) {
                curr += power[i] - extra[i];
                //Printer::print(i, curr, rem);
                if (curr >= x) {
                    continue;
                }

                long long need = x - curr;
                if (need > rem) {
                    return false;
                }
                rem -= need;
                curr += need;
                int right = min(n, i + 2 * r + 1);
                if (right < n) {
                    extra[right] += need;
                }
            }

            return true;
        };

        long long left = 0, right = 1e15;
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            //Printer::print(left, mid, right, f(mid));
            if (f(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
    vector<int> output = {
        5,
        4,
        5,
        52
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 1, 2, 4, 5, 0 },
        { 4, 4, 4, 4 },
        { 4, 4, 4, 4 },
        { 13, 12, 8, 14, 7 }
    };
    vector<int> input2 = {
        1,
        0,
        0,
        2
    };
    vector<int> input3 = {
        2,
        3,
        4,
        23
    };
};