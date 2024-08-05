#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

class KthDistinctStringInAnArray {
public:
    // 7 ms, faster than 99.07% : 18.26 MB, less than 55.44%
    string solution(vector<string> arr, int k)
    {
        unordered_map<string, int> f;
        for (auto& s : arr)
            f[s]++;
        for (auto& s : arr)
            if (f[s] == 1 && k > 1)
                k--;
            else if (f[s] == 1)
                return s;

        return "";
    }
    vector<string> output = {
        "a",
        "aaa",
        ""
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "d", "b", "c", "b", "c", "a" },
        { "aaa", "aa", "a" },
        { "a", "b", "a" }
    };
    vector<int> input2 = {
        2,
        1,
        3
    };
};