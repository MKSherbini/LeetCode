#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet

class FindBuildingWhereAliceAndBobCanMeet {
public:
    // 40 ms, faster than 99.36% : 249.46 MB, less than 82.8%
    vector<int> solution(vector<int> heights, vector<vector<int>> queries)
    {
        int n = size(heights), m = size(queries);

        vector<tuple<int, int, int>> q;
        vector<int> ans(m, -1);
        for (size_t i = 0; i < m; i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b)
                swap(a, b);

            if (heights[a] < heights[b] || a == b)
                ans[i] = b;
            else
                q.push_back({ b, heights[a], i });
        }
        sort(begin(q), end(q), greater());

        vector<int> st;
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!empty(st) && heights[st.back()] <= heights[i]) {
                st.pop_back();
            }

            while (j < size(q)) {
                auto [start, val, ansI] = q[j];
                if (start == i) {
                    int res = -1;
                    int low = 0, high = size(st) - 1;
                    while (low <= high) {
                        int mid = (high + low) / 2;
                        if (heights[st[mid]] > val)
                            low = mid + 1, res = st[mid];
                        else
                            high = mid - 1;
                    }
                    ans[ansI] = res;
                    j++;
                } else if (start > i)
                    j++;
                else
                    break;
            }

            st.push_back(i);
        }

        return ans;
    }
    int search(int height, vector<pair<int, int>>& monoStack)
    {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
    vector<vector<int>> output = {
        { 2, 5, -1, 5, 2 },
        { 7, 6, -1, 4, 6 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 6, 4, 8, 5, 2, 7 },
        { 5, 3, 8, 2, 6, 1, 4, 6 }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1 }, { 0, 3 }, { 2, 4 }, { 3, 4 }, { 2, 2 } },
        { { 0, 7 }, { 3, 5 }, { 5, 2 }, { 3, 0 }, { 1, 6 } }
    };
};