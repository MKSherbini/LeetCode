#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/

class MinimumNumberOfMovesToSeatEveryone {
public:
    // 0 ms, faster than 100% : 20.81 MB, less than 85.02%
    int solution(vector<int> seats, vector<int> students)
    {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int n = size(seats);
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            ans += abs(seats[i] - students[i]);
        }

        return ans;
    }
    vector<int> output = {
        4,
        7,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 1, 5 },
        { 4, 1, 5, 9 },
        { 2, 2, 6, 6 }
    };
    vector<vector<int>> input2 = {
        { 2, 7, 4 },
        { 1, 3, 2, 6 },
        { 1, 3, 2, 6 }
    };
};