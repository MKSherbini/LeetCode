#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-ideal-subsequence/

class LongestIdealSubsequence {
public:
    // 22 ms, faster than 99.58% : 11.3 MB, less than 100%
    int solution(string s, int k)
    {
        int n = size(s);
        vector mem(26, 0);
        mem[s[0] - 'a'] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int best = 0;
            for (int c = max(0, s[i] - 'a' - k); c <= min(25, s[i] - 'a' + k); c++) {
                best = max(best, mem[c]);
            }
            mem[s[i] - 'a'] = best + 1;
            ans = max(ans, best + 1);
        }

        Printer::print(mem);
        return ans;
    }

    // 273 ms, faster than 43.28% : 183.1 MB, less than 38.23%
    int solution3(string s, int k)
    {
        int n = size(s);
        vector mem(n, vector(26, 0));
        mem[0][s[0] - 'a'] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                if (abs(s[i] - 'a' - c) <= k)
                    mem[i][s[i] - 'a'] = max(mem[i][s[i] - 'a'], mem[i - 1][c] + 1);

                if (s[i] - 'a' != c)
                    mem[i][c] = mem[i - 1][c];
            }
            ans = max(ans, mem[i][s[i] - 'a']);
        }

        Printer::print(mem);
        return ans;
    }

    // meh
    int solution2(string s, int k)
    {
        int n = size(s);
        vector mem(n, vector(27, -1));
        function<int(int, char, int)> f = [&](int i, char c, int score) -> int {
            if (i == n)
                return Printer::print("pick: ", c, score), score;

            int& ret = mem[i][c == -1 ? 0 : c - 'a' + 1];
            if (ret != -1)
                return ret;

            ret = f(i + 1, -1, 0);
            if (c == -1 || abs(c - s[i]) <= k)
                Printer::print("pick: ", c, s[i], score), ret = max(ret, f(i + 1, s[i], score + 1));

            return ret;
        };
        f(0, -1, 0);
        Printer::print(mem);
        return f(0, -1, 1);
    }
    vector<int> output = {
        4,
        4,
        5
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "acfgbd",
        "abcd",
        "eduktdb"
    };
    vector<int> input2 = {
        2,
        3,
        15
    };
};