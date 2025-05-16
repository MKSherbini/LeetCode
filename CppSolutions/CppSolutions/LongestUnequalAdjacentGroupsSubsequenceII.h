#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii

class LongestUnequalAdjacentGroupsSubsequenceII {
public:
    // 31 ms, faster than 96.09% : 34.29 MB, less than 93.75%
    vector<string> solution(vector<string> words, vector<int> groups)
    {
        int n = words.size();

        auto hamming = [&](int i, int j) {
            if (words[i].size() != words[j].size()) {
                return false;
            }

            int ret = 0;
            for (int k = 0; k < words[i].size(); k++) {
                if (words[i][k] != words[j][k]) {
                    ret++;
                    if (ret > 1) {
                        return false;
                    }
                }
            }
            return ret == 1;
        };

        vector mem(n, -1), prev(n, -1);
        int mx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (hamming(i, j) && mem[j] + 1 > mem[i] && groups[i] != groups[j]) {
                    mem[i] = mem[j] + 1;
                    prev[i] = j;
                }
            }
            if (mem[i] > mem[mx]) {
                mx = i;
            }
        }

        vector<string> ans;
        while (mx != -1) {
            ans.push_back(words[mx]);
            mx = prev[mx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    //
    vector<string> solution2(vector<string> words, vector<int> groups)
    {
        int n = words.size();

        auto hamming = [&](int i, int j) {
            if (words[i].size() != words[j].size()) {
                return false;
            }

            int ret = 0;
            for (int k = 0; k < words[i].size(); k++) {
                if (words[i][k] != words[j][k]) {
                    ret++;
                    if (ret > 1) {
                        return false;
                    }
                }
            }
            return ret == 1;
        };

        vector mem(n, vector<int>(n, -1));
        function<int(int, int)> f = [&](int i, int last) -> int {
            if (i == n) {
                return 0;
            }
            if (last != -1 && mem[i][last] != -1) {
                return mem[i][last];
            }

            int ret = f(i + 1, last);
            if (last == -1 || hamming(i, last) && groups[i] != groups[last]) {
                ret = max(ret, f(i + 1, i) + (int)size(words[i]));
            }

            if (last != -1)
                return mem[i][last] = ret;
            return ret;
        };

        Printer::print(f(0, -1));
        Printer::print(mem);
        return {};
    }
    vector<vector<string>> output = {
        { "bab", "cab" },
        { "a", "b", "c", "d" }
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "bab", "dab", "cab" },
        { "a", "b", "c", "d" }
    };
    vector<vector<int>> input2 = {
        { 1, 2, 2 },
        { 1, 2, 3, 4 }
    };
};