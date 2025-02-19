#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

class TheKThLexicographicalStringOfAllHappyStringsOfLengthN {
public:
    // 0 ms, faster than 100% : 8.86 MB, less than 81.36%
    string solution(int n, int k)
    {
        string row;
        function<bool()> f = [&]() -> bool {
            Printer::print(row);
            if (size(row) == n) {
                if (--k == 0) {
                    return true;
                }
                return false;
            }
            char last = empty(row) ? 'x' : row.back();

            for (char c : { 'a', 'b', 'c' }) {
                if (c == last)
                    continue;

                row.push_back(c);
                if (f())
                    return true;
                row.pop_back();
            }

            return false;
        };

        f();
        return row;
    }
    vector<string> output = {
        "c",
        "",
        "cab"
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        1,
        1,
        3
    };
    vector<int> input2 = {
        3,
        4,
        9
    };
};