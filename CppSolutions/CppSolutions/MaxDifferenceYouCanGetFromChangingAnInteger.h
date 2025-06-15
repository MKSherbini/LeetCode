#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer

class MaxDifferenceYouCanGetFromChangingAnInteger {
public:
    // 0 ms, faster than 100% : 8.27 MB, less than 43.13%
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

        if (s[0] != '1') {
            for (size_t j = 1; j < n; j++) {
                if (s[j] == s[0]) {
                    s[j] = '1';
                }
            }
            s[0] = '1';
        } else {
            for (size_t i = 1; i < n; i++) {
                if (s[i] > '1') {
                    char c = s[i];
                    for (size_t j = i; j < n; j++) {
                        if (s[j] == c) {
                            s[j] = '0';
                        }
                    }
                    break;
                }
            }
        }

        return mx - stoi(s);
    }
    vector<int> output = {
        888,
        8,
        820000,
        888,
        8808050
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        555,
        9,
        123456,
        111,
        1101057
    };
};