#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/

class TheNumberOfTheSmallestUnoccupiedChair {
public:
    // 113 ms, faster than 99.31% : 54.72 MB, less than 97.59%
    int solution(vector<vector<int>> times, int targetFriend)
    {
        int n = size(times);
        int targetArrival = times[targetFriend][0];
        sort(begin(times), end(times), [](const auto& a, const auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });

        priority_queue<int, vector<int>, greater<int>> seats;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaveTimes;

        int nextSeat = 0;
        for (size_t i = 0; i < n; i++) {
            while (!empty(leaveTimes) && leaveTimes.top().first <= times[i][0]) {
                seats.push(leaveTimes.top().second);
                leaveTimes.pop();
            }

            int seat = 0;
            if (empty(seats)) {
                leaveTimes.push({ times[i][1], seat = nextSeat++ });
            } else {
                leaveTimes.push({ times[i][1], seat = seats.top() });
                seats.pop();
            }

            if (times[i][0] == targetArrival)
                return seat;
        }

        return 66;
    }
    vector<int> output = {
        1,
        2
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 4 }, { 2, 3 }, { 4, 6 } },
        { { 3, 10 }, { 1, 5 }, { 2, 6 } }
    };
    vector<int> input2 = {
        1,
        0
    };
};