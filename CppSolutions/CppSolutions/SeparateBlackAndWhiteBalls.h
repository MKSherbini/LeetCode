#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/separate-black-and-white-balls/description/

class SeparateBlackAndWhiteBalls {
public:
    // 30 ms, faster than 77.26% : 15.42 MB, less than 89.89%
    int solution(string s)
    {
        int i = 0, j = size(s) - 1;

        long long ans = 0;
        while (i < j) {
            if (s[i] == '0') {
                i++;
            } else if (s[j] == '1') {
                j--;
            } else {
                ans += j - i;
                i++, j--;
            }
        }

        return ans;
    }

    // 110 ms, faster than 5.05% : 25.32 MB, less than 6.32%
    int solution2(string s)
    {
        int n = size(s);
        priority_queue<int> pq;
        for (size_t i = 0; i < n; i++) {
            if (s[i] == '0')
                pq.push(i);
        }

        long long ans = 0;
        for (size_t i = 0; i < n; i++) {
            if (s[i] == '0')
                continue;

            if (empty(pq) || pq.top() <= i)
                break;

            ans += pq.top() - i;
            pq.pop();
        }

        return ans;
    }
    vector<int> output = {
        1,
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "101",
        "100",
        "0111"
    };
};