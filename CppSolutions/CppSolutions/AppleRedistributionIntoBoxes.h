#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/apple-redistribution-into-boxes

class AppleRedistributionIntoBoxes {
public:
    // 0 ms, faster than 100% : 32.92 MB, less than 92.82%
    int solution(vector<int> apple, vector<int> capacity)
    {
        sort(capacity.begin(), capacity.end(), greater());
        int totalApples = accumulate(apple.begin(), apple.end(), 0);

        int n = apple.size(), m = capacity.size();
        for (size_t i = 0; i < m; i++) {
            totalApples -= capacity[i];
            if (totalApples <= 0)
                return i + 1;
        }

        return 66;
    }
    // WA wrong question :V
    int solution2(vector<int> apple, vector<int> capacity)
    {
        sort(capacity.begin(), capacity.end(), greater());
        set<int> s;
        for (int a : apple)
            s.insert(-a);

        int n = apple.size(), m = capacity.size();
        for (size_t i = 0; i < m; i++) {
            if (s.empty())
                return i;

            auto it = s.begin();
            while (!s.empty() && (it = s.lower_bound(-capacity[i])) != s.end()) {
                capacity[i] += (*it);
                Printer::print(capacity[i], *it);
                s.erase(it);
            }
        }

        return s.empty() ? m : -1;
    }
    vector<int> output = {
        2,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 3, 2 },
        { 5, 5, 5 }
    };
    vector<vector<int>> input2 = {
        { 4, 3, 1, 5, 2 },
        { 2, 4, 2, 7 }
    };
};