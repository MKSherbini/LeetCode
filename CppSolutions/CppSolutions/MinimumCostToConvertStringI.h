#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class MinimumCostToConvertStringI {
public:
    // 154 ms, faster than 82.8% : 101.82 MB, less than 43.41%
    int solution(string source, string target, vector<char> original, vector<char> changed, vector<int> cost)
    {
        const int OO = 1e8 + 7;
        vector<vector<pair<char, int>>> adj(26);
        vector mem(26, vector<int>(26, OO));
        for (size_t i = 0; i < size(original); i++) {
            adj[original[i] - 'a'].push_back({ cost[i], changed[i] - 'a' });
            mem[original[i] - 'a'][changed[i] - 'a'] = min(mem[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (size_t i = 0; i < 26; i++) {
            mem[i][i] = 0;
        }

        for (size_t k = 0; k < 26; k++) {
            for (size_t i = 0; i < 26; i++) {
                for (size_t j = 0; j < 26; j++) {
                    mem[i][j] = min(mem[i][j], mem[i][k] + mem[k][j]);
                }
            }
        }

        long long ans = 0;
        for (size_t i = 0; i < size(source); i++) {
            if (mem[source[i] - 'a'][target[i] - 'a'] >= OO)
                return -1;
            ans += mem[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
    vector<int> output = {
        28,
        12,
        -1
    };
    static constexpr int const& inputs = 5;
    vector<string> input1 = {
        "abcd",
        "aaaa",
        "abcd"
    };
    vector<string> input2 = {
        "acbe",
        "bbbb",
        "abce"
    };
    vector<vector<char>> input3 = {
        { 'a', 'b', 'c', 'c', 'e', 'd' },
        { 'a', 'c' },
        { 'a' }
    };
    vector<vector<char>> input4 = {
        { 'b', 'c', 'b', 'e', 'b', 'e' },
        { 'c', 'b' },
        { 'e' }
    };
    vector<vector<int>> input5 = {
        { 2, 5, 5, 1, 2, 20 },
        { 1, 2 },
        { 10000 }
    };
};