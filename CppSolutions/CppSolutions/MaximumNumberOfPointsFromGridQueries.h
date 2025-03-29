#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries

class MaximumNumberOfPointsFromGridQueries {
public:
    // 195 ms, faster than 29.71% : 61.91 MB, less than 28.99%
    vector<int> solution(vector<vector<int>> grid, vector<int> queries)
    {
        int n = grid.size(), m = grid[0].size(), nq = queries.size();

        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return grid[a.first][a.second] > grid[b.first][b.second];
        };
        auto cmp2 = [&](const int a, const int b) {
            return queries[a] > queries[b];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        priority_queue<int, vector<int>, decltype(cmp2)> pq2(cmp2);

        pq.push({ 0, 0 });
        for (int i = 0; i < nq; i++) {
            pq2.push(i);
        }

        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };

        vector<int> ans(nq, 0);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;
        int c = 0;
        while (!pq2.empty()) {
            int q = queries[pq2.top()];

            while (!pq.empty() && grid[pq.top().first][pq.top().second] < q) {
                auto [x, y] = pq.top();
                pq.pop();
                c++;

                const vector<pair<int, int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
                for (auto [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;
                    if (valid(nx, n) && valid(ny, m) && vis[nx][ny] != 1) {
                        pq.push({ nx, ny });
                        vis[nx][ny] = 1;
                    }
                }
                Printer::print("x: ", x, " y: ", y, " q: ", q);
            }
            ans[pq2.top()] = c;
            pq2.pop();
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 5, 8, 1 },
        { 0 },
        { 4, 3 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 3 }, { 2, 5, 7 }, { 3, 5, 1 } },
        { { 5, 2, 1 }, { 1, 1, 2 } },
        { { 123491, 95183, 131119, 576084, 779700, 886039, 564610 },
            { 835246, 594630, 752204, 976312, 431928, 916878, 37773 },
            { 602559, 675, 8018, 72760, 560850, 132858, 416126 },
            { 787316, 77587, 784798, 797907, 769783, 143785, 378185 },
            { 362862, 754648, 212843, 813454, 552332, 10700, 266493 },
            { 970387, 690405, 956929, 172955, 952240, 156111, 403784 },
            { 916537, 511212, 795823, 716447, 470772, 943050, 542971 },
            { 449416, 742776, 952272, 447280, 190229, 354861, 256967 },
            { 682983, 738563, 29191, 379588, 802026, 480129, 88803 },
            { 200621, 935415, 758897, 430413, 947532, 642396, 281230 },
            { 11009, 169593, 224388, 165812, 668820, 197039, 370824 },
            { 69652, 613219, 858695, 278982, 688142, 592221, 573682 },
            { 169510, 983952, 45500, 536012, 460040, 22352, 30370 },
            { 80353, 162875, 946697, 861329, 680011, 716224, 528454 },
            { 752578, 92518, 914849, 76979, 957241, 215103, 428977 },
            { 882979, 485485, 371229, 191577, 428367, 22769, 668112 } }
    };
    vector<vector<int>> input2 = {
        { 5, 6, 2 },
        { 3 },
        { 581002, 174698 }
    };
};