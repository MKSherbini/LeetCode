#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/partition-labels

class PartitionLabels {
public:
    // 0 ms, faster than 100% : 8.66 MB, less than 97.09%
    vector<int> solution(string s)
    {
        int n = s.size();
        vector<int> last(26, 0);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int end = last[s[i] - 'a'];
            for (int j = i + 1; j <= end; j++)
                end = max(end, last[s[j] - 'a']);
            ans.push_back(end - i + 1);
            i = end;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 9, 7, 8 },
        { 10 }
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "ababcbacadefegdehijhklij",
        "eccbbbbdec"
    };
};