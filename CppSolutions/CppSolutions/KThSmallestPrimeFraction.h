#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

class KThSmallestPrimeFraction {
public:
    // 343 ms, faster than 38.69% : 11.87 MB, less than 85.49%
    vector<int> solution(vector<int> arr, int k)
    {
        auto cmp = [&](const auto& x, const auto& y) { return 1.0 * arr[x.first] / arr[x.second] > 1.0 * arr[y.first] / arr[y.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        int n = size(arr);
        for (size_t i = 0; i < n - 1; i++) {
            pq.push({ i, n - 1 });
        }

        Printer::print(pq);
        while (--k) {
            auto [i, j] = pq.top();
            pq.pop();
            if (i < j - 1)
                pq.push({ i, j - 1 }); 
        }

        return { arr[pq.top().first], arr[pq.top().second] };
    }
    vector<vector<int>> output = {
        { 2, 5 },
        { 1, 7 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 5 },
        { 1, 7 }
    };
    vector<int> input2 = {
        3,
        1
    };
};