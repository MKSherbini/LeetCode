#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/description/

class PalindromePartitioning {
public:
    // 56 ms, faster than 99.31% : 52.5 MB, less than 99.04%
    vector<vector<string>> solution(string s)
    {
        int n = size(s);
        auto isPalindrome = [&](int i, int j) {
            while (i < j && s[i] == s[j]) {
                i++, j--;
            }
            return i >= j;
        };

        vector<string> row;
        vector<vector<string>> ans;
        function<void(int)> f = [&](int st) -> void {
            if (st == n) {
                ans.push_back(row);
            }

            for (size_t end = st; end < n; end++) {
                if (isPalindrome(st, end)) {
                    row.push_back(s.substr(st, end - st + 1));
                    f(end + 1);
                    row.pop_back();
                }
            }
        };

        f(0);
        return ans;
    }

    // bad + duplicates
    vector<vector<string>> solution2(string s)
    {
        int n = size(s);
        auto isPalindrome = [&](int i, int j) {
            while (i < j && s[i] == s[j]) {
                i++, j--;
            }
            return i >= j;
        };

        function<vector<vector<string>>(int, int)> f = [&](int i, int j) -> vector<vector<string>> {
            vector<vector<string>> ret;
            Printer::print(i, j);
            if (isPalindrome(i, j))
                ret.push_back({ s.substr(i, j - i + 1) });
            for (size_t d = i; d < j; d++) {
                auto x = f(i, d), y = f(d + 1, j);
                if (empty(x) || empty(y))
                    continue;

                for (auto& s : x) {
                    for (auto& s2 : y) {
                        ret.push_back({});
                        ret.back().insert(end(ret.back()), begin(s), end(s));
                        ret.back().insert(end(ret.back()), begin(s2), end(s2));
                    }
                }
            }

            return ret;
        };

        return f(0, n - 1);
    }
    vector<vector<vector<string>>> output = {
        { { "a", "a", "b" }, { "aa", "b" } },
        { { "a" } }
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "aab",
        "a"
    };
};