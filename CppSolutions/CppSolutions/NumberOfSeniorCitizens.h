#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-senior-citizens/description/

class NumberOfSeniorCitizens {
public:
    // 3 ms, faster than 91.87% : 17.44 MB, less than 31.37%
    int solution(vector<string> details)
    {
        int ans = 0;
        for (auto& s : details)
            if (stoi(s.substr(11, 2)) > 60)
                ans++;

        return ans;
    }
    vector<int> output = {
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "7868190130M7522", "5303914400F9211", "9273338290F4010" },
        { "1313579440F2036", "2921522980M5644" }
    };
};