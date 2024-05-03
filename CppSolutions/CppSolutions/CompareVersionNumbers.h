#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/compare-version-numbers/

class CompareVersionNumbers {
public:
    // 0 ms, faster than 100% : 7.7 MB, less than 27.77%
    int solution(string version1, string version2)
    {
        std::stringstream ss1(version1), ss2(version2);
        string s1, s2;
        while (getline(ss1, s1, '.') && getline(ss2, s2, '.')) {
            int i1 = stoi(s1), i2 = stoi(s2);
            if (i1 != i2)
                return i1 > i2 ? 1 : -1;
            s1 = s2 = "0";
        }
        int i1 = stoi(s1), i2 = stoi(s2);
        if (i1 != i2)
            return i1 > i2 ? 1 : -1;

        while (getline(ss1, s1, '.')) {
            int i1 = stoi(s1);
            if (i1 != 0)
                return i1 > 0 ? 1 : -1;
        }

        while (getline(ss2, s2, '.')) {
            int i2 = stoi(s2);
            if (i2 != 0)
                return i2 > 0 ? -1 : 1;
        }

        return 0;
    }
    vector<int> output = {
        0,
        0,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "1.01",
        "1.0",
        "0.1"
    };
    vector<string> input2 = {
        "1.001",
        "1.0.0",
        "1.1"
    };
};