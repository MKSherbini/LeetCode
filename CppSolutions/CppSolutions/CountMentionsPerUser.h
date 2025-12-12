#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-mentions-per-user

class CountMentionsPerUser {
public:
    // 24 ms, faster than 76.6% : 40.63 MB, less than 85.82%
    vector<int> solution(int numberOfUsers, vector<vector<string>> events)
    {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            return stoi(a[1]) == stoi(b[1]) ? a[0] > b[0] : stoi(a[1]) < stoi(b[1]);
        });
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offline(numberOfUsers, 0);
        for (const auto& event : events) {
            if (event[0] == "MESSAGE") {
                int time = stoi(event[1]);
                string content = event[2];
                if (content == "ALL") {
                    for (int userId = 0; userId < numberOfUsers; ++userId) {
                        mentions[userId]++;
                    }
                } else if (content == "HERE") {
                    for (int userId = 0; userId < numberOfUsers; ++userId) {
                        if (offline[userId] <= time) {
                            mentions[userId]++;
                        }
                    }
                } else {
                    for (const auto& s : views::split(content, ' ')) {
                        int userId = stoi(string(s.begin() + 2, s.end()));
                        mentions[userId]++;
                    }
                }

            } else {
                int time = stoi(event[1]);
                int userId = stoi(event[2]);
                offline[userId] = time + 60;
            }
        }

        return mentions;
    }
    vector<vector<int>> output = {
        { 2, 2 },
        { 2, 2 },
        { 0, 1 }
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        2,
        2,
        2
    };
    vector<vector<vector<string>>> input2 = {
        { { "MESSAGE", "10", "id1 id0" }, { "OFFLINE", "11", "0" }, { "MESSAGE", "71", "HERE" } },
        { { "MESSAGE", "10", "id1 id0" }, { "OFFLINE", "11", "0" }, { "MESSAGE", "12", "ALL" } },
        { { "OFFLINE", "10", "0" }, { "MESSAGE", "12", "HERE" } }
    };
};