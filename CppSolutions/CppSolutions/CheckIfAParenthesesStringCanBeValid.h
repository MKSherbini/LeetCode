#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class CheckIfAParenthesesStringCanBeValid {
public:
    // 8 ms, faster than 90.45% : 34.6 MB, less than 24.87%
    uint8_t solution(string s, string locked)
    {
        int n = size(s);
        if (n % 2 == 1) {
            return false;
        }

        stack<int> unlocked, open;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        while (!empty(open) && !empty(unlocked) && open.top() < unlocked.top()) {
            open.pop();
            unlocked.pop();
        }

        if (!empty(open)) {
            return false;
        }

        return true;
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "))()))",
        "()()",
        ")"
    };
    vector<string> input2 = {
        "010100",
        "0000",
        "0"
    };
};