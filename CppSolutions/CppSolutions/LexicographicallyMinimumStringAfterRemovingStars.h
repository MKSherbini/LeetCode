#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars

class LexicographicallyMinimumStringAfterRemovingStars {
public:
    // 164 ms, faster than 29.21% : 23.33 MB, less than 97.75%
    string solution(string s)
    {
        int n = s.size();
        auto cmp = [&](int i, int j) {
            return s[i] != s[j] ? s[i] > s[j] : i < j;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (size_t i = 0; i < n; i++) {
            Printer::print(pq);
            if (s[i] == '*') {
                s[pq.top()] = '*';
                pq.pop();
            } else {
                pq.push(i);
            }
        }

        string ans;
        for (size_t i = 0; i < n; i++) {
            if (s[i] != '*') {
                ans += s[i];
            }
        }

        return ans;
    }
    vector<string> output = {
        "aab",
        "abc"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "aaba*",
        "abc"
    };
};