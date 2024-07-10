#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/crawler-log-folder/description/

class CrawlerLogFolder {
public:
    // 0 ms, faster than 100% : 13.74 MB, less than 96.6%
    int solution(vector<string> logs)
    {
        int n = size(logs);
        int ans = 0;
        int ignores = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (logs[i] == "../")
                ignores++;
            else if (logs[i] == "./")
                ;
            else {
                if (ignores > 0)
                    ignores--;
                else
                    ans++;
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        3,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "d1/", "d2/", "../", "d21/", "./" },
        { "d1/", "d2/", "./", "d3/", "../", "d31/" },
        { "d1/", "../", "../", "../" }
    };
};