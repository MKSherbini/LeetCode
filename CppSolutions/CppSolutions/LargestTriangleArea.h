#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/largest-triangle-area

class LargestTriangleArea {
public:
    // 0 ms, faster than 100% : 10.36 MB, less than 86.95%
    double solution(vector<vector<int>> points)
    {
        double maxArea = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double area = 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) +
                                            points[j][0] * (points[k][1] - points[i][1]) +
                                            points[k][0] * (points[i][1] - points[j][1]));
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    vector<double> output = {
        2.00000,
        0.50000
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 0, 2 }, { 2, 0 } },
        { { 1, 0 }, { 0, 0 }, { 0, 1 } }
    };
};