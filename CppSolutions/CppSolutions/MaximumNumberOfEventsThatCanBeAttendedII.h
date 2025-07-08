#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

class MaximumNumberOfEventsThatCanBeAttendedII {
public:
    // 1540 ms, faster than 5.11% : 434.78 MB, less than 5.11%
    int solution(vector<vector<int>> events, int k)
    {
        sort(begin(events), end(events), [](const auto& a, const auto b) { return a[0] < b[0]; });
        int n = size(events);

        vector<int> next(n);
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (events[mid][0] <= events[i][1]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            next[i] = l;
        }

        vector mem(n + 1, vector(k + 1, -1));
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                if (j == 0 || i == n) {
                    mem[i][j] = 0;
                } else {
                    mem[i][j] = max(mem[i + 1][j],
                        events[i][2] + mem[next[i]][j - 1]);
                }
            }
        }

        return mem[0][k];
    }

    // TLE
    int solution3(vector<vector<int>> events, int k)
    {
        sort(begin(events), end(events), [](const auto& a, const auto b) { return a[0] < b[0]; });
        int n = size(events);

        vector<int> next(n);
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (events[mid][0] <= events[i][1]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            next[i] = l;
        }

        vector mem(n, vector(k + 1, -1));
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (j == 0 || i == n) {
                return 0;
            }
            if (mem[i][j] != -1) {
                return mem[i][j];
            }
            return mem[i][j] = max(f(i + 1, j),
                       events[i][2] + f(next[i], j - 1));
        };

        return f(0, k);
    }

    // 864 ms, faster than 5.05% : 188.5 MB, less than 5.05%
    int solution2(vector<vector<int>> events, int k)
    {
        sort(begin(events), end(events), [](const auto& a, const auto b) { return a[0] < b[0]; });
        int n = size(events);

        function<int(int, int)> find = [&](int i, int l) -> int {
            int r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (events[mid][0] <= i) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };

        vector mem(n, vector(k + 1, -1));
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (j == 0 || i == n) {
                return 0;
            }
            if (mem[i][j] != -1) {
                return mem[i][j];
            }
            int nextIndex = find(events[i][1], i + 1);
            return mem[i][j] = max(f(i + 1, j),
                       events[i][2] + f(nextIndex, j - 1));
        };

        return f(0, k);
    }
    vector<int> output = {
        7,
        10,
        9
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 4 }, { 3, 4, 3 }, { 2, 3, 1 } },
        { { 1, 2, 4 }, { 3, 4, 3 }, { 2, 3, 10 } },
        { { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 } }
    };
    vector<int> input2 = {
        2,
        2,
        3
    };
};