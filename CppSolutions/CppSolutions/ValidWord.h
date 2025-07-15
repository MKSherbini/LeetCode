#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/valid-word

class ValidWord {
public:
    // 0 ms, faster than 100% : 7.77 MB, less than 97.82%
    uint8_t solution(string word)
    {
        if (word.size() < 3) {
            return false;
        }

        bool vowoel = false, consonant = false;
        for (char c : word) {
            if (!isalnum(c)) {
                return false;
            }
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowoel = true;
            } else if (!isdigit(c)) {
                consonant = true;
            }
        }

        return vowoel && consonant;
    }
    vector<uint8_t> output = {
        true,
        false,
        false
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "234Adas",
        "b3",
        "a3$e"
    };
};