#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/candy/

class Candy
{
public:
    // 18 ms, faster than 96.91% : 17.1 MB, less than 99.45%
    int solution(vector<int> ratings) {
        int sz = size(ratings);
        int ans = sz;

        int i = 1;
        while (i < sz)
        {
            if (ratings[i] == ratings[i - 1]) {
                ++i;
                continue;
            }

            int x = 0;
            while (i<sz && ratings[i] > ratings[i - 1])
                ans += ++x, ++i;

            int y = 0;
            while (i < sz && ratings[i] < ratings[i - 1])
                ans += ++y, ++i;

            ans -= min(x, y);
        }

        return ans;
    }

    // 20 ms, faster than 93.75% : 17.1 MB, less than 99.45%
    int solution2(vector<int> ratings) {
        int sz = size(ratings);
        int ans = sz;

        int i = 1;
        while (i < sz)
        {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int x = 1;
            while (i<sz && ratings[i] > ratings[i - 1])
                ans += x++, i++;

            int y = 1;
            while (i<sz && ratings[i] < ratings[i - 1])
                ans += y++, i++;

            ans -= min(x, y) - 1;
        }

        return ans;
    }
    vector<int> output = {
        5,
        4,
        7,
        13
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        {1,0,2},
        {1,2,2},
        {1,3,2,2,1},
        {1,2,87,87,87,2,1}
    };
};