#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/distribute-candies-among-children-ii

class DistributeCandiesAmongChildrenII {
public:
    // 31 ms, faster than 26.47% : 8.76 MB, less than 99.41%
    int solution(int n, int limit)
    {
        long long ans = 0;
        for (int i = 0; i <= min(limit,n); i++) {
            if (n - i > 2 * limit) {
                continue;
            }

            ans += min(n - i, limit) - max(0, n - i - limit) + 1;
        }

        return ans;
    }
    vector<int> output = {
        3,
        10
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        5,
        3
    };
    vector<int> input2 = {
        2,
        3
    };
};