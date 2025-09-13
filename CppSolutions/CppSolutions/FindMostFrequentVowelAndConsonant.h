#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant

class FindMostFrequentVowelAndConsonant {
public:
    // 0 ms, faster than 100% : 9.19 MB, less than 96.23%
    int solution(string s)
    {
        vector<int> v(26, 0);
        int maxVowel = 0, maxConsonant = 0;
        string vowels = "aeiou";
        for (char c : s) {
            if (vowels.find(c) != -1) {
                v[c - 'a']++;
                maxVowel = max(maxVowel, v[c - 'a']);
            } else {
                v[c - 'a']++;
                maxConsonant = max(maxConsonant, v[c - 'a']);
            }
        }

        return maxVowel + maxConsonant;
    }
    vector<int> output = {
        6,
        3
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "successes",
        "aeiaeia"
    };
};