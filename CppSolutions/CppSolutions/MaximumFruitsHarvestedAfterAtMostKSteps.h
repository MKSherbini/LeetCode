#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps

class MaximumFruitsHarvestedAfterAtMostKSteps {
public:
    // 12 ms, faster than 53.25% : 132.09 MB, less than 39.84%
    int solution(vector<vector<int>> fruits, int startPos, int k)
    {
        auto it = lower_bound(fruits.begin(), fruits.end(), vector<int> { startPos, 0 }, [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        //  1-800-225-5345
        vector<pair<int, int>> l, r;
        if (it != fruits.begin()) {
            for (auto i = it - 1;; --i) {
                if (startPos - i->at(0) > k)
                    break;
                l.emplace_back(i->at(0), i->at(1) + (l.empty() ? 0 : l.back().second));
                if (i == fruits.begin())
                    break;
            }
        }

        for (auto i = it; i != fruits.end(); ++i) {
            if (i->at(0) - startPos > k)
                break;
            r.emplace_back(i->at(0), i->at(1) + (r.empty() ? 0 : r.back().second));
        }

        Printer::print(l, r);
        int ans = 0;
        for (size_t i = 0; i < l.size(); i++) {
            int left = k - (startPos - l[i].first);
            auto it = upper_bound(r.begin(), r.end(), make_pair(l[i].first + left, 0), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });
            ans = max(ans, l[i].second + (it == r.begin() ? 0 : prev(it)->second));
        }

        reverse(l.begin(), l.end());
        for (int i = 0; i < r.size(); ++i) {
            int left = k - (r[i].first - startPos);
            auto it = lower_bound(l.begin(), l.end(), make_pair(r[i].first - left, 0), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });
            ans = max(ans, r[i].second + (it != l.end() ? it->second : 0));
        }

        return ans;
    }
    vector<int> output = {
        9,
        14,
        0,
        10000
    };
    static constexpr int const& inputs = 3;
    vector<vector<vector<int>>> input1 = {
        { { 2, 8 }, { 6, 3 }, { 8, 6 } },
        { { 0, 9 }, { 4, 1 }, { 5, 7 }, { 6, 2 }, { 7, 4 }, { 10, 9 } },
        { { 0, 3 }, { 6, 4 }, { 8, 5 } },
        { { 200000, 10000 } }
    };
    vector<int> input2 = {
        5,
        5,
        3,
        200000
    };
    vector<int> input3 = {
        4,
        4,
        2,
        200000
    };
};