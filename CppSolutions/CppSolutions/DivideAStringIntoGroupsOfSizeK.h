#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k

class DivideAStringIntoGroupsOfSizeK {
public:
    // 0 ms, faster than 100% : 9.7 MB, less than 93.73%
    vector<string> solution(string s, int k, char fill)
    {
        vector<string> ans;
        int n = s.size();
        for (int i = 0; i < n; i += k) {
            string t = s.substr(i, k);
            if (t.size() < k) {
                t.append(k - t.size(), fill);
            }
            ans.push_back(t);
        }
        return ans;
    }
    vector<vector<string>> output = {
        { "abc", "def", "ghi" },
        { "abc", "def", "ghi", "jxx" }
    };
    static constexpr int const& inputs = 3;
    vector<string> input1 = {
        "abcdefghi",
        "abcdefghij"
    };
    vector<int> input2 = {
        3,
        3
    };
    vector<char> input3 = {
        'x',
        'x'
    };
};