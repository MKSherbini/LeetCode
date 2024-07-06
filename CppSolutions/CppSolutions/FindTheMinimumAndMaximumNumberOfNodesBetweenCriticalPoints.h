#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

class FindTheMinimumAndMaximumNumberOfNodesBetweenCriticalPoints {
public:
    // 207 ms, faster than 5.42% : 115.72 MB, less than 79.36%
    vector<int> solution(ListNode* head)
    {
        int mn = INT_MAX, mx = 0;
        int prev = head->val;
        int c = INT_MIN;
        while (head && head->next) {
            if ((prev > head->val && head->next->val > head->val) || (prev < head->val && head->next->val < head->val)) {
                if (c > 0)
                    mn = min(mn, c), mx += c;
                c = 0;
            }
            c++;
            prev = head->val;
            head = head->next;
        }

        return { mn == INT_MAX ? -1 : mn, mx == 0 ? -1 : mx };
    }
    vector<vector<int>> output = {
        { -1, -1 },
        { 1, 3 },
        { 3, 3 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 1 },
        { 5, 3, 1, 2, 5, 1, 2 },
        { 1, 3, 2, 2, 3, 2, 2, 2, 7 }
    };
};