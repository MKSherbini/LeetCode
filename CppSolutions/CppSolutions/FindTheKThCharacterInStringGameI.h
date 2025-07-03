#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i

class FindTheKThCharacterInStringGameI {
public:
    // 0 ms, faster than 100% : 9.56 MB, less than 67.19%
    char solution(int k)
    {
        string s = "a";
        while (s.size() < k) {
            string t = s;
            for (auto& c : t) {
                c = char('a' + (c - 'a' + 1) % 26);
            }
            s += t;
        }

        return s[k - 1];
    }
    vector<char> output = {
        'b',
        'c'
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        5,
        10
    };
};