#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/reverse-prefix-of-word/

class ReversePrefixOfWord {
public:
    // 0 ms, faster than 100% : 7.3 MB, less than 91.39%
    string solution(string word, char ch)
    {
        int it = word.find_first_of(ch);
        if (it != -1)
            reverse(begin(word), begin(word) + it + 1);
        return word;
    }
    vector<string> output = {
        "dcbaefd",
        "zxyxxe",
        "abcd"
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "abcdefd",
        "xyxzxe",
        "abcd"
    };
    vector<char> input2 = {
        'd',
        'z',
        'z'
    };
};