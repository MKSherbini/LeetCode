#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

class MaximumDifferenceByRemappingADigit {
public:
    // 0 ms, faster than 100% : 8.16 MB, less than 64.15%
    int solution(int num)
    {
        string s = to_string(num);
        int n = s.size();
        int mx = num;
        for (size_t i = 0; i < n; i++) {
            if (s[i] != '9') {
                char c = s[i];
                for (size_t j = i; j < n; j++) {
                    if (s[j] == c) {
                        s[j] = '9';
                    }
                }
                mx = stoi(s);
                s = to_string(num);
                break;
            }
        }

        for (size_t j = 1; j < n; j++) {
            if (s[j] == s[0]) {
                s[j] = '0';
            }
        }
        s[0] = '0';


        return mx - stoi(s);
    }
    vector<int> output = {
        99009,
        99,
        99999
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        11891,
        90,
        99999
    };
};