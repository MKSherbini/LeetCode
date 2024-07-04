#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/merge-nodes-in-between-zeros/

class MergeNodesInBetweenZeros {
public:
    // 382 ms, faster than 97.6% : 256.5 MB, less than 88.28%
    ListNode* solution(ListNode* head)
    {
        auto ans = head->next;
        auto it = ans;
        while (it && it->next) {
            if (it->next->val == 0)
                it->next = it->next->next, it = it->next;
            else
                it->val += it->next->val, it->next = it->next->next;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 4, 11 },
        { 1, 3, 4 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 0, 3, 1, 0, 4, 5, 2, 0 },
        { 0, 1, 0, 3, 0, 2, 2, 0 }
    };
};