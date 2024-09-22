#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

class KThSmallestInLexicographicalOrder {
public:
    // 0 ms, faster than 100% : 7.22 MB, less than 97.21%
    int solution(int n, int k)
    {
        auto calcSteps = [&](long long prefix1, long long prefix2) {
            long long steps = 0;
            while (prefix1 <= n) {
                steps += min(n + 1ll, prefix2) - prefix1;
                prefix1 *= 10;
                prefix2 *= 10;
            }
            return steps;
        };

        int cur = 1;
        k--;

        while (k > 0) {
            int steps = calcSteps(cur, cur + 1);

            if (steps <= k) { // if we can skip current node traversal
                cur++;
                k -= steps;
            } else { // depth traverse current node
                cur *= 10;
                k--;
            }
        }

        return cur;
    }
    vector<int> output = {
        10,
        1
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        13,
        1
    };
    vector<int> input2 = {
        2,
        1
    };
};