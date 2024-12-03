#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/adding-spaces-to-a-string

class AddingSpacesToAString {
public:
    // 11 ms, faster than 96.69% : 85.39 MB, less than 20.79%
    string solution(string s, vector<int> spaces)
    {
        string ans;
        int j = 0;
        for (size_t i = 0; i < size(s); i++) {
            if (j < size(spaces) && spaces[j] == i)
                ans += " ", j++;
            ans += s[i];
        }

        return ans;
    }
    vector<string> output = {
        "Leetcode Helps Me Learn",
        "i code in py thon",
        " s p a c i n g"
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "LeetcodeHelpsMeLearn",
        "icodeinpython",
        "spacing"
    };
    vector<vector<int>> input2 = {
        { 8, 13, 15 },
        { 1, 5, 7, 9 },
        { 0, 1, 2, 3, 4, 5, 6 }
    };
};