#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-happy-string/description/

class LongestHappyString {
public:
    // 0 ms, faster than 100% : 7.4 MB, less than 97.08%
    string solution(int a, int b, int c)
    {
        vector<pair<int, char>> v = { { a, 'a' }, { b, 'b' }, { c, 'c' } };
        string ans;
        sort(begin(v), end(v), greater());
        while (!empty(v) && v[0].first > 0) {
            if (v[0].first > v[1].first && v[1].first != 0) {
                ans += string(2, v[0].second);
                ans += string(1, v[1].second);
                v[0].first -= 2;
                v[1].first--;
            } else if (v[0].first == v[1].first) {
                ans += string(1, v[0].second);
                ans += string(1, v[1].second);
                v[0].first--;
                v[1].first--;
            } else {
                break;
            }
            sort(begin(v), end(v), greater());
            Printer::print(v, ans);
        }
        if (v[0].first > 0)
            ans += string(min(2, v[0].first), v[0].second);

        return ans;
    }
    vector<string> output = {
        "ccaccbcc",
        "aabaa",
        "bbaabbc"
    };
    static constexpr int const& inputs = 3;
    vector<int> input1 = {
        1,
        7,
        2
    };
    vector<int> input2 = {
        1,
        1,
        4
    };
    vector<int> input3 = {
        7,
        0,
        1
    };
};