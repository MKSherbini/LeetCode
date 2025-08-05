#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/fruits-into-baskets-ii

class FruitsIntoBasketsII {
public:
    // 0 ms, faster than 100% : 48.78 MB, less than 92.36%
    int solution(vector<int> fruits, vector<int> baskets)
    {
        int ans = fruits.size();
        for (size_t i = 0; i < fruits.size(); i++) {
            for (size_t j = 0; j < baskets.size(); j++) {
                if (fruits[i] <= baskets[j]) {
                    ans--;
                    baskets[j] = 0;
                    break;
                }
            }
        }

        return ans;
    }
    vector<int> output = {
        1,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 2, 5 },
        { 3, 6, 1 }
    };
    vector<vector<int>> input2 = {
        { 3, 5, 4 },
        { 6, 4, 7 }
    };
};