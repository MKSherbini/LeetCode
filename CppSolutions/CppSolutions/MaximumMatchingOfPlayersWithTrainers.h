#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-matching-of-players-with-trainers

class MaximumMatchingOfPlayersWithTrainers {
public:
    // 21 ms, faster than 97.54% : 80.03 MB, less than 97.54%
    int solution(vector<int> players, vector<int> trainers)
    {
        int n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, ans = 0;
        for (size_t j = 0; j < m && i < n; j++) {
            if (trainers[j] >= players[i]) {
                ans++;
                i++;
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 7, 9 },
        { 1, 1, 1 }
    };
    vector<vector<int>> input2 = {
        { 8, 2, 5, 8 },
        { 10 }
    };
};