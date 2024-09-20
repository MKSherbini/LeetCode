#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/shortest-palindrome/description/

class ShortestPalindrome {
public:
    // 0 ms, faster than 100% : 10.29 MB, less than 81.47%
    string solution(string s)
    {
        if (s == "")
            return s;

        string pattern(s.rbegin(), s.rend());
        int len = kmp(pattern, s);

        return pattern.substr(0, size(s) - len) + s;
    }

    int kmp(std::string& s, std::string& pattern)
    {
        int n = size(s), m = size(pattern);

        // lps
        vector<int> lps(m);
        lps[0] = 0;
        int len = 0;
        for (int i = 1; i < m;) {
            if (pattern[i] == pattern[len]) {
                lps[i] = ++len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }

        // kmp
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == pattern[j]) {
                i++, j++;
                if (j == m) {
                    Printer::print(i - j);
                    j = lps[j - 1];
                    return n;
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }

            Printer::print(i, j);
        }

        return j;
    }

    // 43 ms, faster than 6.55% : 716.04 MB, less than 5.09%
    string solution2(string s)
    {
        // abca
        // acba

        string r(s.rbegin(), s.rend());
        for (size_t i = 0; i < size(r); i++) {
            if (s.starts_with(r.substr(i)))
                return r.substr(0, i) + s;
        }

        return r + s;
    }
    vector<string> output = {
        "aaacecaaa",
        "dcbabcd",
        "aa"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "aacecaaa",
        "abcd",
        "aa"
    };
};