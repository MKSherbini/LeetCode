#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-square-sum-triples

class CountSquareSumTriples {
public:
    // 3 ms, faster than 90.49% : 7.88 MB, less than 55.75%
    int solution(int n)
    {
        int ans = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = a; b <= n; ++b) {
                int c2 = a * a + b * b;
                int c = (int)sqrt(c2);
                if (c * c == c2 && c <= n) {
                    if (a == b)
                        ans += 1;
                    else
                        ans += 2;
                }
            }
        }
        return ans;
    }
    vector<int> output = {
        2,
        4
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        5,
        10
    };
};