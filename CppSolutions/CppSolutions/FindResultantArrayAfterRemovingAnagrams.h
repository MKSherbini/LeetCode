#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

class FindResultantArrayAfterRemovingAnagrams {
public:
    // 0 ms, faster than 100% : 15.83 MB, less than 96.97%
    vector<string> solution(vector<string> words)
    {
        vector<string> ans;
        string prev = "";
        for (const auto& w : words) {
            string t = w;
            sort(t.begin(), t.end());
            if (t != prev) {
                ans.push_back(w);
                prev = t;
            }
        }
        return ans;
    }
    vector<vector<string>> output = {
        { "abba", "cd" },
        { "a", "b", "c", "d", "e" }
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "abba", "baba", "bbaa", "cd", "cd" },
        { "a", "b", "c", "d", "e" }
    };
};