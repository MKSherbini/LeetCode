#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sliding-puzzle

class SlidingPuzzle {
public:
    // 14 ms, faster than 34.94% : 13.5 MB, less than 29.91%
    int solution(vector<vector<int>> board)
    {
        string goal = "123450";

        unordered_map<string, int> dis;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        pq.push({ 0, to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]) });

        while (!empty(pq)) {
            auto [d, s] = pq.top();
            pq.pop();

            if (s == goal)
                return d;

            if (dis.count(s) && d > dis[s])
                continue;

            dis[s] = d;

            auto it = s.find('0');
            if (it != 5 && it != 2) {
                swap(s[it], s[it + 1]);
                pq.push({ d + 1, s });
                swap(s[it], s[it + 1]);
            }
            if (it != 0 && it != 3) {
                swap(s[it], s[it - 1]);
                pq.push({ d + 1, s });
                swap(s[it], s[it - 1]);
            }
            swap(s[it], s[(it + 3) % 6]);
            pq.push({ d + 1, s });
        }

        return -1;
    }
    vector<int> output = {
        1,
        -1,
        5
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 3 }, { 4, 0, 5 } },
        { { 1, 2, 3 }, { 5, 4, 0 } },
        { { 4, 1, 2 }, { 5, 0, 3 } }
    };
};