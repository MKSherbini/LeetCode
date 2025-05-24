#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-words-containing-character

class FindWordsContainingCharacter {
public:
    // 0 ms, faster than 100% : 32.85 MB, less than 97.25%
    vector<int> solution(vector<string> words, char x)
    {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<vector<int>> output = {
        { 0, 1 },
        { 0, 2 },
        {}
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "leet", "code" },
        { "abc", "bcd", "aaaa", "cbc" },
        { "abc", "bcd", "aaaa", "cbc" }
    };
    vector<char> input2 = {
        'e',
        'a',
        'z'
    };
};