#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/open-the-lock/

class OpenTheLock {
public:
    // 86 ms, faster than 90.73% : 38.8 MB, less than 56.9%
    int solution(vector<string> deadends, string target)
    {
        unordered_set<string> s;
        for (auto x : deadends)
            s.insert(x);

        unordered_set<string> vis(begin(deadends), end(deadends));

        if (vis.count("0000"))
            return -1;

        queue<string> q;
        q.push("0000");

        int ans = 0;
        while (!empty(q)) {
            int c = size(q);
            while (c--) {
                auto& cur = q.front();

                if (cur == target)
                    return ans;

                for (size_t i = 0; i < 4; i++) {
                    int c = cur[i] - '0';
                    cur[i] = ((c + 1) % 10) + '0';
                    if (!vis.count(cur))
                        q.push(cur), vis.insert(cur);
                    cur[i] = ((c + 9) % 10) + '0';
                    if (!vis.count(cur))
                        q.push(cur), vis.insert(cur);
                    cur[i] = c + '0';
                }
                q.pop();
            }

            ans++;
        }

        return -1;
    }
    vector<int> output = {
        6,
        1,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "0201", "0101", "0102", "1212", "2002" },
        { "8888" },
        { "8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888" }
    };
    vector<string> input2 = {
        "0202",
        "0009",
        "8888"
    };
};