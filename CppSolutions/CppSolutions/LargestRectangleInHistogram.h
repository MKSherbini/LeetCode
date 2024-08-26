#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class LargestRectangleInHistogram {
public:
    // 99 ms, faster than 86.74% : 84.22 MB, less than 48.07%
    int solution(vector<int> heights)
    {
        int n = size(heights);
        if (n == 1)
            return heights[0];

        stack<int> st;
        vector<int> minLeft(n), minRight(n);
        for (int i = 0; i < n; i++) {
            while (!empty(st) && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!empty(st))
                minLeft[i] = st.top();
            else
                minLeft[i] = -1;
            st.push(i);
        }

        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!empty(st) && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!empty(st))
                minRight[i] = st.top();
            else
                minRight[i] = n;
            st.push(i);
        }

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            ans = max(ans, (minRight[i] - minLeft[i] - 1) * heights[i]);
        }
        Printer::print(minLeft, minRight);

        return ans;
    }
    vector<int> output = {
        10,
        4,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 1, 5, 6, 2, 3 },
        { 2, 4 },
        { 1, 1 }
    };
};