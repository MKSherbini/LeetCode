#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-center-of-star-graph/description/

class FindCenterOfStarGraph {
public:
    // 122 ms, faster than 92.25% : 70.7 MB, less than 92.91%
    int solution(vector<vector<int>> edges)
    {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
    vector<int> output = {
        2,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 2, 3 }, { 4, 2 } },
        { { 1, 2 }, { 5, 1 }, { 1, 3 }, { 1, 4 } }
    };
};