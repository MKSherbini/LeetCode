#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string

class UsingARobotToPrintTheLexicographicallySmallestString {
public:
    // 79 ms, faster than 30.2% : 34.94 MB, less than 36.63%
    string solution(string s)
    {
        int n = s.size();

        unordered_map<char, int> c;
        for (int i = 0; i < n; ++i) {
            c[s[i]]++;
        }

        string t;
        string ans;
        char j = 'a';
        for (int i = 0; i < n; ++i) {
            t += s[i];
            c[s[i]]--;
            while (j < 'z' && c[j] == 0) {
                ++j;
            }
            while (!t.empty() && t.back() <= j) {
                ans += t.back();
                t.pop_back();
            }
        }
        return ans;
    }
    vector<string> output = {
        "azz",
        "abc",
        "addb",
        "fnohopzv"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "zza",
        "bac",
        "bdda",
        "vzhofnpo"
    };
};