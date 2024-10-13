#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

class SmallestRangeCoveringElementsFromKLists {
public:
    // 42 ms, faster than 67.94% : 27.31 MB, less than 10.19%
    vector<int> solution(vector<vector<int>> nums)
    {
        set<pair<int, int>> s;
        int n = size(nums);
        for (size_t i = 0; i < n; i++) {
            for (auto x : nums[i]) {
                s.insert({ x, i });
            }
        }

        auto it1 = begin(s), it2 = begin(s);
        unordered_map<int, int> m;
        vector<int> ans(2);
        ans[1] = INT_MAX;
        while (it2 != end(s)) {
            if (m[it2->second]++ == 0)
                n--;

            if (n == 0) {
                while (n == 0) {
                    if (--m[it1->second] == 0)
                        n++;
                    it1 = next(it1);
                }
                if ((it2->first - prev(it1)->first) < (ans[1] - ans[0])) {
                    ans[0] = prev(it1)->first;
                    ans[1] = it2->first;
                    Printer::print(*prev(it1), *it2);
                }
            }

            it2 = next(it2);
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 20, 24 },
        { 1, 1 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 4, 10, 15, 24, 26 }, { 0, 9, 12, 20 }, { 5, 18, 22, 30 } },
        { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } }
    };
};