#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/letter-tile-possibilities

class LetterTilePossibilities {
public:
    // 29 ms, faster than 46.64% : 16.58 MB, less than 49.48%
    int solution(string tiles)
    {
        int n = tiles.size();
        string row;
        unordered_set<string> s;
        function<void()> dfs = [&]() {
            s.insert(row);
            for (int i = 0; i < n; i++) {
                if (tiles[i] == 'x')
                    continue;
                row.push_back(tiles[i]);
                tiles[i] = 'x';
                dfs();
                tiles[i] = row.back();
                row.pop_back();
            }
        };
        dfs();
        return s.size() - 1;
    }
    vector<int> output = {
        8,
        188,
        1
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "AAB",
        "AAABBC",
        "V"
    };
};