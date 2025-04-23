#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-largest-group

class CountLargestGroup {
public:
    // 2 ms, faster than 49.15% : 8.09 MB, less than 57.97%
    int solution(int n)
    {
        unordered_map<int, int> m;
        int ans = 0;
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            int num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            m[sum]++;

            if (m[sum] > mx) {
                mx = m[sum];
                ans = 1;
            } else if (m[sum] == mx) {
                ans++;
            }
        }

        return ans;
    }
    vector<int> output = {
        4,
        2
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        13,
        2
    };
};