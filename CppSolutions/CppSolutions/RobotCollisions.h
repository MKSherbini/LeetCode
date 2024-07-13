#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/robot-collisions/description/

class RobotCollisions {
public:
    // 178 ms, faster than 97.41% : 218.5 MB, less than 57.04%
    vector<int> solution(vector<int> positions, vector<int> healths, string directions)
    {
        int n = size(positions);
        vector<tuple<int, int, char, int>> v;
        for (size_t i = 0; i < n; i++)
            v.push_back({ positions[i], healths[i], directions[i], i });

        sort(begin(v), end(v));
        stack<pair<int, int>> st;
        vector<pair<int, int>> temp;
        for (size_t i = 0; i < n; i++) {
            auto [pos, hp, dir, idx] = v[i];
            if (dir == 'R') {
                st.push({ idx, hp });
                continue;
            }

            while (!empty(st) && hp > 0) {
                Printer::print(st.top(), hp);
                if (st.top().second == hp)
                    st.pop(), hp = 0;
                else if (st.top().second < hp)
                    st.pop(), hp--;
                else {
                    st.top().second--, hp = 0;
                    if (st.top().second == 0)
                        st.pop();
                }
            }

            if (empty(st) && hp > 0) {
                temp.push_back({ idx, hp });
            }
        }

        int sz = size(st);
        while (!empty(st)) {
            temp.push_back(st.top());
            st.pop();
        }
        sort(begin(temp), end(temp));
        vector<int> ans(size(temp));
        for (size_t i = 0; i < size(temp); i++) {
            ans[i] = temp[i].second;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 2, 17, 9, 15, 10 },
        { 14 },
        {}
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 5, 4, 3, 2, 1 },
        { 3, 5, 2, 6 },
        { 1, 2, 5, 6 }
    };
    vector<vector<int>> input2 = {
        { 2, 17, 9, 15, 10 },
        { 10, 10, 15, 12 },
        { 10, 10, 11, 11 }
    };
    vector<string> input3 = {
        "RRRRR",
        "RLRL",
        "RLRL"
    };
};